/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 07:30:19 by javgonza         ###   ########.fr       */
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
		if (streq((char *)builtins[i].name, name))
			return (builtins[i].builtin);
		i++;
	}
	return (NULL);
}

int	execute_command_string_form(char *command, char **args)
{
	int			executed;
	char		**path_split;
	size_t		i;
	t_builtin	builtin;

	builtin = find_builtin_by_name(args[0]);
	if (builtin != NULL)
	{
		g_minishell_data.error_code = 0;
		builtin(args);
		return (0);
	}
/*	if (streq(command, "cd"))
	{
		builtin_cd(args);
		return (0);
	}
	if (streq(command, "authors"))
	{
		builtin_authors(args);
		return (0);
	}
	if (streq(command, "export"))
	{
		builtin_export(args);
		return (0);
	}
	if (streq(command, "env"))
	{
		builtin_env(args);
		return (0);
	}
	if (streq(command, "pwd"))
	{
		builtin_pwd(args);
		return (0);
	}
	if (streq(command, "unset"))
	{
		builtin_unset(args);
		return (0);
	}
	if (streq(command, "echo"))
	{
		builtin_echo(args);
		return (0);
	}
	if (streq(command, "exit"))
	{
		builtin_exit(args);
		return (0);
	}*/
	executed = execute_command_from_path(command, args, NULL);
	if (executed != 0)
	{
		path_split = ft_split(g_minishell_data.path.value, ':');
		if (path_split != NULL)
		{
			i = 0;
			while (executed != 0 && path_split[i] != NULL)
			{
				executed = try_to_execute_command_on_folder(path_split[i], command, args, NULL);
				i++;
			}
			ft_freearray(path_split);
		}
	}
	if (executed != 0)
		printf(MINISHELL_PROMPT"Comando falla\n");
	return (executed);
}
