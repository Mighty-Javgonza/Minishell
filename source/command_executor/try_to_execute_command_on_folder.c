/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_execute_command_on_folder.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:02:08 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:29:20 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../env_variables/env_variables.h"

static char	*normal_join(char *path, char *command)
{
	char	*command_path;

	command_path = ft_strjoin(path, command);
	return (command_path);
}

static char	*join_with_slash(char *path, char *command)
{
	char	*command_path;
	char	*path_with_slash;

	path_with_slash = ft_strjoin(path, "/");
	command_path = ft_strjoin(path_with_slash, command);
	free(path_with_slash);
	return (command_path);
}

int	try_to_execute_command_on_folder(char *path, char *command, char **args,
			char **env)
{
	char	*command_path;
	int		executed;

	if (path[ft_strlen(path)] == '/')
		command_path = normal_join(path, command);
	else
		command_path = join_with_slash(path, command);
	executed = execute_command_from_path(command_path, args, env);
	free(command_path);
	return (executed);
}
