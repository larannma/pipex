#include "pipex.h"
#include "libft.h"

void	init_struct(int argc, char **argv, char **envp, t_struct *p)
{
	if (argc != 5)
	{
		ft_putstr_fd("Use 4 argumens!\n", 2);
		ft_putstr_fd("Example: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit (1);
	}
	p->envp = envp;
	p->file1 = argv[1];
	p->file2 = argv[4];
	p->argv = argv;
	p->argc = argc;
	get_cmds(p);
}
