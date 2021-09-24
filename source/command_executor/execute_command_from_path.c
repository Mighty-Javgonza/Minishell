/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_from_path.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:37:27 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:24 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../env_variables/env_variables.h"

int	execute_command_from_path(char *command_path, char **args, char **env)
{
	pid_t	pid;
	int		error_code;

	error_code = 0;
	g_minishell_data.error_code = 0;
	pid = fork();
	if (pid == 0)
	{
		error_code = execve(command_path, args, env);
		exit(error_code);
	}
	else
	{
		waitpid(pid, &error_code, 0);
		g_minishell_data.error_code = error_code;
	}
	return (error_code);
}
