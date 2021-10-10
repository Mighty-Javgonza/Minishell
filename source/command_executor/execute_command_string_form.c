/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 10:14:00 by javgonza         ###   ########.fr       */
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

static void	try_command_on_all_paths(char *command,
			char **args, int *executed, char **env)
{
	size_t	i;
	char	**path_split;

	path_split = ft_split(g_minishell_data.path.value, ':');
	if (path_split == NULL)
		return ;
	i = 0;
	while (*executed == 0 && path_split[i] != NULL && g_minishell_data.error_code != ERROR_IS_A_DIRECTORY)
	{
		*executed = try_to_execute_command_on_folder(path_split[i],
				command, args, env);
		i++;
	}
	ft_freearray(path_split);
}

static void	print_error_message(char *command)
{
	if (g_minishell_data.error_code == ERROR_COMMAND_NOT_FOUND)
		printf(MINISHELL_PROMPT"El comando %s no existe\n", command);
	else if (g_minishell_data.error_code == ERROR_IS_A_DIRECTORY)
		printf(MINISHELL_PROMPT"%s es un directorio\n", command);
	else if (g_minishell_data.error_code == ERROR_SEGFAULT)
		printf(MINISHELL_PROMPT"Segmentation fault\n");
//	else if (!g_minishell_data.cancelling_command)
//		printf(MINISHELL_PROMPT"Comando falla\n");
}

int	execute_command_string_form(char *command, char **args)
{
	t_builtin	builtin;
	int			executed;
	char		**env;

	(void)args;
	builtin = find_builtin_by_name(args[0]);
	if (builtin != NULL)
	{
		g_minishell_data.error_code = 0;
		builtin(args);
		return (0);
	}
	executed = 0;
	env = env_vars_to_arr();
	if (ft_strncmp(command, "./", 2) == 0)
		executed = execute_command_from_path(command, args, env);
	else
		try_command_on_all_paths(command, args, &executed, env);
	if (g_minishell_data.error_code != 0)
		print_error_message(command);
	ft_freearray(env);
	return (executed);
}
