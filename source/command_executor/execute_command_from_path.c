/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_from_path.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:37:27 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/01 09:01:22 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../env_variables/env_variables.h"

static int	check_path_is_valid(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 2)
		return (0);
	else
	{
		close(fd);
		return (1);
	}
}

int	execute_command_from_path(char *command_path, char **args, char **env)
{
	pid_t	pid;
	int		error_code;

	error_code = 0;
	g_minishell_data.error_code = 0;
	g_minishell_data.cancelling_command = 0;
	g_minishell_data.command_exists = check_path_is_valid(command_path);
	if (g_minishell_data.command_exists == 0)
	{
		g_minishell_data.error_code = ERROR_COMMAND_NOT_FOUND;
		return (0);
	}
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
	return (1);
}
