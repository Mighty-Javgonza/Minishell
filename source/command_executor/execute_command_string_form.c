/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/30 10:32:21 by javgonza         ###   ########.fr       */
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
		{
			return (g_builtins[i].builtin);
		}
		i++;
	}
	return (NULL);
}

static void	try_command_on_all_paths(char **path_split, char *command,
			char **args, int *executed)
{
	size_t	i;

	i = 0;
	while (*executed != 0 && path_split[i] != NULL)
	{
		*executed = try_to_execute_command_on_folder(path_split[i],
				command, args, NULL);
		i++;
	}
	ft_freearray(path_split);
}


int	execute_command_string_form(char *command, char **args)
{
	char		**path_split;
	t_builtin	builtin;
	int			executed;

	(void)args;
	builtin = find_builtin_by_name(args[0]);
	if (builtin != NULL)
	{
		g_minishell_data.error_code = 0;
		builtin(args);
		return (0);
	}
	executed = 0;
	executed = execute_command_from_path(command, args, NULL);
	if (executed != 0)
	{
		path_split = ft_split(g_minishell_data.path.value, ':');
		if (path_split != NULL)
			try_command_on_all_paths(path_split, command, args, &executed);
	}
	if (executed != 0)
	{
		if (g_minishell_data.cancelling_command != 0)
			printf(MINISHELL_PROMPT"Comando falla\n");
	}
	return (executed);
}
