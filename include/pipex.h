#ifndef     PIPEX_H
# define    PIPEX_H

# include   <unistd.h>
# include   <stdio.h>
# include	<fcntl.h>

typedef struct s_command
{
	int			fd[2];
	char		*program_name;
	char		**program_argv;
}				t_command;

typedef struct s_struct
{
	char		**envp;
	char		*file1;
	char		*file2;
	int			fd[2];
	char		**argv;
	int			argc;
	t_command	commands[2];
}			t_struct;

void	init_struct(int argc, char **argv, char **envp, t_struct *p);
void	get_cmds(t_struct *p);
void	*return_and_free_pointer(void *return_pointer, void *pointer_to_free);
void	split_free(char **split, char **current_pos);

#endif