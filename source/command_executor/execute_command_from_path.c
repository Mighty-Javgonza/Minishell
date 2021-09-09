/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_from_path.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:37:27 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/09 12:58:21 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	execute_command_from_path(char *command_path, char **args, char **env)
{
	pid_t	pid;
	int		error_code;

	error_code = 0;
	pid = fork();
	if (pid == 0)
	{
		error_code = execve(command_path, args, env);
		exit(error_code);
	}
	else
	{
		waitpid(pid, &error_code, 0);
	}
	return (error_code);
}
