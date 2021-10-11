/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:34:15 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

t_builtin	find_builtin_by_name(char *name)
{
	size_t	i;

	i = 0;
	while (i < BUILTIN_COUNT)
	{
		if (streq((char *)g_builtins[i].name, name))
			return (g_builtins[i].builtin);
		i++;
	}
	return (NULL);
}

static int	try_command_on_all_paths(char *command, char *path_var,
			char **args, char **env)
{
	size_t	i;
	char	**path_split;
	int		executed;

	path_split = ft_split(path_var, ':');
	if (path_split == NULL)
	{
		g_minishell_data.error_code = ERROR_COMMAND_NOT_FOUND;
		return (0);
	}
	i = 0;
	executed = 0;
	while (executed == 0 && path_split[i] != NULL
		&& g_minishell_data.error_code != ERROR_NO_SUCH_FILE_OR_DIRECTORY)
	{
		executed = try_to_execute_command_on_folder(path_split[i],
				command, args, env);
		i++;
	}
	ft_freearray(path_split);
	return (executed);
}

static void	print_error_message(char *command)
{
	if (g_minishell_data.error_code == ERROR_COMMAND_NOT_FOUND)
		printf(MINISHELL_PROMPT"El comando %s no existe\n", command);
	else if (g_minishell_data.error_code == ERROR_IS_A_DIRECTORY)
		printf(MINISHELL_PROMPT"%s es un directorio\n", command);
	else if (g_minishell_data.error_code == ERROR_SEGFAULT)
		printf(MINISHELL_PROMPT"Segmentation fault\n");
}

int	execute_command_string_form(char *command, char **args,
		t_env_var_list *env_vars)
{
	t_builtin	builtin;
	int			executed;
	char		**env;

	(void)args;
	builtin = find_builtin_by_name(args[0]);
	if (builtin != NULL)
	{
		g_minishell_data.error_code = 0;
		builtin(args, env_vars);
		return (0);
	}
	executed = 0;
	env = env_vars_to_arr(env_vars);
	if (ft_strncmp(command, "./", 2) == 0 || command[0] == '/')
		executed = execute_command_from_path(command, args, env);
	else
		executed = try_command_on_all_paths(command, env_vars->path.value,
				args, env);
	if (g_minishell_data.error_code != 0)
		print_error_message(command);
	if (env != NULL)
		ft_freearray(env);
	return (executed);
}
