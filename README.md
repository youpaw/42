# 42sh

**42sh** is a POSIX-compatible Unix shell written from scratch in C, developed as a team project at [School 42](https://42.fr/). It implements its own lexer, parser, expansion engine, executor, job control, and interactive line editor, relying only on standard system calls and `termcap` — no GNU readline or other shell libraries.

## Features

### Interactive editing
- Custom line editor with cursor movement, Home/End, and multi-line input
- Tab-completion for commands, files, and variables
- Command history with navigation, persistence across sessions, and `!` history expansion
- UTF-8 aware input handling

### Command language
- POSIX shell grammar: pipelines, `&&` / `||` lists, `;` and `&` separators, `!` negation
- Redirections: `<`, `>`, `>>`, `<&`, `>&`, with file-descriptor numbers
- Here-documents: `<<` and `<<-`
- Variable assignments and environment handling
- Expansions: parameters (`$VAR`), tilde (`~`), exit status (`$?`), arithmetic (`$((...))`)
- Aliases

### Job control
- Background and foreground execution with full process-group management
- `jobs`, `fg`, `bg` builtins and `Ctrl-C` / `Ctrl-Z` signal handling
- Asynchronous job status notifications

### Built-in commands
`cd`, `echo`, `set`, `unset`, `env`, `export`, `alias`, `unalias`, `hash`, `history`, `type`, `jobs`, `fg`, `bg`, `exit`

## Architecture

Input is processed in stages, each implemented as a separate library under `src/lib/`:

```
readline  →  liblex  →  libparse  →  libexpand  →  libexec / libjob
 (input)    (tokens)     (AST)     (expansions)      (execution)
```

| Module | Purpose |
|---|---|
| `readline` | Interactive line editing, completion, history navigation |
| `liblex` | Tokenizer for the POSIX shell grammar |
| `libparse` | Recursive-descent parser producing an AST |
| `libexpand` | Parameter, tilde, arithmetic, and history expansion |
| `libexec` | Command resolution and execution, redirections, pipes |
| `libjob` | Process groups, signals, job queue and notifications |
| `libcalc` | Arithmetic evaluator (shunting-yard) for `$((...))` |
| `libhash` | `$PATH` lookup cache (the `hash` builtin) |
| `libenv`, `libalias`, `libhistory`, `liberror` | Environment, aliases, history, error reporting |
| `libcc` | In-house C standard library ([submodule](https://github.com/youpaw/libcc)) |

The formal grammar the parser follows is documented in [doc/lexem.txt](doc/lexem.txt).

## Building

Requirements: a C99 compiler, `make`, `cmake` ≥ 3.8, and `termcap`.

```sh
git clone --recurse-submodules https://github.com/youpaw/42.git
cd 42
cmake . && make
```

If you already cloned without submodules:

```sh
git submodule update --init
```

## Usage

```sh
./42sh
```

Non-interactive use:

```sh
echo 'echo $((2 + 2))' | ./42sh
```

## License

[MIT](LICENSE)
