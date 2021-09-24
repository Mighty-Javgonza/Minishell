/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 06:49:09 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

//TODO: Pass env vars

static void	builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		chdir(g_minishell_data.home.value);
		set_variable("PWD", g_minishell_data.home.value);
	}
	else
	{
		chdir(args[1]);
		set_variable("PWD", args[1]);
	}
}

static void	builtin_authors(char **args)
{
	char	*jav_path;
	char	*baz_path;
	char	*auth_args[3];

	(void)args;
	jav_path = PROJECT_DIR"/authors/facegonza.term";
	baz_path = PROJECT_DIR"/authors/facezuara.term";
	auth_args[0] = "cat";
	auth_args[1] = baz_path;
	auth_args[2] = NULL;
	execute_command_string_form(auth_args[0], auth_args);
	auth_args[1] = jav_path;
	execute_command_string_form(auth_args[0], auth_args);
}

static void	builtin_export(char **vars_to_export)
{
	size_t			i;
	char			**split;

	i = 1;
	while (vars_to_export[i] != NULL)
	{
		load_env_variable(vars_to_export[i]);
		split = ft_split(vars_to_export[i], '=');
		export_var(split[0]);
		ft_freearray(split);
		i++;
	}
}

static void	builtin_env(char **args)
{
	(void)args;
	print_env_vars();
}

static void	builtin_pwd(char **args)
{
	(void)args;
	char	path[10000];

	getcwd(path, 10000);
	printf("%s\n", path);
}

static void	builtin_unset(char **args)
{
	t_env_variable	*var;

	args++;
	while (*args != NULL)
	{
		var = find_env_var(*args);
		var->is_local = 1;
		args++;
	}
}

static void	builtin_echo(char **args)
{
	int				writes_nl;

	writes_nl = 1;
	args++;
	if (streq(args[0], "-n"))
	{
		writes_nl = 0;
		args++;
	}
	while (*args != NULL)
	{
		printf("%s", *args);
		args++;
	}
	if (writes_nl)
		printf("\n");
}

static void	builtin_exit(char **args)
{
	(void)args;
	exit(0);
}

int	execute_command_string_form(char *command, char **args)
{
	int		executed;
	char	**path_split;
	size_t	i;

	if (streq(command, "cd"))
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
	}
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
