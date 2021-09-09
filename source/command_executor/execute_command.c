/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/09 13:25:25 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"

//TODO: Pass env vars

int	execute_command(char *command, char **args)
{
	int		executed;
	char	**path_split;
	size_t	i;

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
