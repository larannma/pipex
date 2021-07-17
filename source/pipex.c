#include "pipex.h"
#include "libft.h"

void	*return_and_free_pointer(void *return_pointer, void *pointer_to_free)
{
	free(pointer_to_free);
	return (return_pointer);
}

void	split_free(char **split, char **current_pos)
{
	(void)split;
	while (*current_pos != NULL)
	{
		free(*current_pos);
		current_pos++;
	}
	free(split);
}

int	safe_open(char *file_name, int flags, int mods)
{
	int	fd;

	fd = open(file_name, flags, mods);
	if (fd < 0)
	{
		perror("open");
		exit(1);
	}
	return (fd);
}

int	safe_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit (1);
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	p;
	t_command	curr_cmd;
	int			pid;
	int			pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit (1);
	init_struct(argc, argv, envp, &p);
	pid = safe_fork();
	if (pid == 0)
	{
		dup2(safe_open(argv[1], O_RDONLY, 0777), 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		curr_cmd = p.commands[0];
		if (execve(curr_cmd.program_name, curr_cmd.program_argv, p.envp) < 0)
			exit (1);
	}
	dup2(safe_open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0664), 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	curr_cmd = p.commands[1];
	if (execve(curr_cmd.program_name, curr_cmd.program_argv, p.envp) < 0)
		exit (1);
}
