/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/16 10:06:40 by javgonza         ###   ########.fr       */
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

static void	restore_stds(int dup_out, int dup_in, t_command *command)
{
	if (dup_out != STDOUT_FILENO)
	{
		dup2(dup_out, STDOUT_FILENO);
		close(dup_out);
	}
	if (dup_in != STDIN_FILENO)
	{
		dup2(dup_in, STDIN_FILENO);
		close(dup_in);
	}
	if (command->output_fd != STDOUT_FILENO)
		close(command->output_fd);
	if (command->input_fd != STDIN_FILENO)
		close(command->input_fd);
}

int	execute_command(t_command *command)
{
	char	**args;
	int		dup_out;
	int		dup_in;

	dup_out = STDOUT_FILENO;
	dup_in = STDIN_FILENO;
	args = get_args_from_tokens(&command->tr, 0);
	if (command->output_fd != STDOUT_FILENO)
	{
		dup_out = dup(STDOUT_FILENO);
		dup2(command->output_fd, STDOUT_FILENO);
	}
	if (command->input_fd != STDIN_FILENO)
	{
		dup_in = dup(STDIN_FILENO);
		dup2(command->input_fd, STDIN_FILENO);
	}
	execute_command_string_form(args[0], args);
	restore_stds(dup_out, dup_in, command);
	return (0);
}
