int pid;

if (!(pid = fork()))
{
make_proc_leader();
//get_term_control();
print_process_stats("List fork:");
exec_and_or(ast->left);
}
else
{
make_proc_leader();
//wait(NULL);
//get_term_control();
if (!ast->token || ast->token->type != l_and)
waitpid(pid, NULL, 0);
if (ast->right)
exec_list(ast->right);
}

void	make_proc_leader(void);
void	get_term_control(void);
if (!(pid = fork()))
{
make_proc_leader();
set_fork_handlers();
//signal (SIGINT, fork_sig_handler);
print_process_stats("exec simple command:");
execve(path, (char *const *) args, (char *const *) exec_env);
}
waitpid(pid, NULL, NULL);



if (!(pid = fork()))
{
print_process_stats("background process:");
exec_and_or(ast->left);
exit(0);
}
else
jobs_add(pid, 0);
