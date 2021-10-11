/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:14:04 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:41:48 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <unistd.h>
#include <stdlib.h>
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

static void	print_error(char **args)
{
	g_minishell_data.error_code = ERROR_NO_SUCH_FILE_OR_DIRECTORY;
	if (args[1] != NULL)
		printf("cd: %s No such file or directory\n", args[1]);
	else
		printf("cd: Home directory not set\n");
}

void	builtin_cd(char **args, t_env_var_list *env_vars)
{
	int		error;
	char	path[10000];

	if (args[1] == NULL)
	{
		error = chdir(env_vars->home.value);
		if (error == 0)
			set_variable(env_vars, "PWD", env_vars->home.value);
	}
	else
	{
		error = chdir(args[1]);
		if (error == 0)
		{
			set_variable(env_vars, "OLDPWD", env_vars->pwd.value);
			getcwd(path, 10000);
			set_variable(env_vars, "PWD", path);
		}
	}
	if (error != 0)
		print_error(args);
}
