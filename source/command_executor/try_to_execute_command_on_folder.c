/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_execute_command_on_folder.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:02:08 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/09 13:04:58 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../env_variables/env_variables.h"

int	try_to_execute_command_on_folder(char *path, char *command, char **args, char **env)
{
	char	*command_path;
	int		executed;

	command_path = ft_strjoin(path, command);
	executed = execute_command_from_path(command_path, args, env);
	free(command_path);
	return (executed);
}
