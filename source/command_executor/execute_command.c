/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:29:11 by javgonza         ###   ########.fr       */
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

static void	open_redirections(t_command *command)
{
	if (command->in_name != NULL
		&& (command->redirect_type & TOKEN_TYPE_REDIRECT_INPUT) != 0)
		open_command_in_redirection(command);
	if (command->out_name != NULL
		&& (command->redirect_type & TOKEN_TYPE_REDIRECT_OUTPUT) != 0)
		open_command_out_redirection(command);
	if (command->out_name != NULL
		&& (command->redirect_type & TOKEN_TYPE_REDIRECT_OUTPUT_APPEND) != 0)
		open_command_out_append_redirection(command);
	if (command->out_name != NULL
		&& (command->redirect_type & TOKEN_TYPE_REDIRECT_OUTPUT_APPEND) != 0)
		open_command_out_append_redirection(command);
}

int	execute_command(t_command *command)
{
	char	**args;
	int		dup_out;
	int		dup_in;

	dup_out = STDOUT_FILENO;
	dup_in = STDIN_FILENO;
	open_redirections(command);
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
	ft_freearray(args);
	restore_stds(dup_out, dup_in, command);
	return (0);
}
