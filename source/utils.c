#include "pipex.h"
#include "libft.h"

char	*leaks_free_strjoin(char *str1, char *str2, int f_str1, int f_str2)
{
	char	*old_str1;
	char	*old_str2;

	old_str1 = str1;
	old_str2 = str2;
	str1 = ft_strjoin(str1, str2);
	if (f_str1)
		free(old_str1);
	if (f_str2)
		free(old_str2);
	return (str1);
}

char	*check(char **env)
{
	char	*path;

	path = NULL;
	while (*env != NULL)
	{
		path = ft_strnstr(*(env++), "PATH=", 5);
		if (path)
			break ;
	}
	path += 5;
	return (path);
}

char	*get_full_path(char *program_name, char **env)
{
	char	*path_save;
	char	**path_array;
	char	**path_array_pointer;

	path_array = ft_split(check(env), ':');
	path_array_pointer = path_array;
	if (access(program_name, X_OK) == 0)
		return (program_name);
	while (*path_array != NULL)
	{
		*path_array = leaks_free_strjoin(*path_array, "/", 1, 0);
		path_save = leaks_free_strjoin(*path_array, program_name, 1, 0);
		if (access(path_save, X_OK) == 0)
		{
			free(program_name);
			split_free(path_array_pointer, path_array + 1);
			return (path_save);
		}
		free(path_save);
		path_array++;
	}
	perror("Couldn't find command");
	return (NULL);
}

void	parse_command(t_command *command, char *raw_command_line, char **env)
{
	char	**splitted_line;

	splitted_line = ft_split(raw_command_line, ' ');
	splitted_line[0] = get_full_path(splitted_line[0], env);
	command->program_name = splitted_line[0];
	command->program_argv = splitted_line;
}

void	get_cmds(t_struct *p)
{
	parse_command(&(p->commands[0]), p->argv[2], p->envp);
	parse_command(&(p->commands[1]), p->argv[3], p->envp);
}
