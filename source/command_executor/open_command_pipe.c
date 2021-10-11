/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_command_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:36:05 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 18:28:42 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <unistd.h>

void	open_command_pipe(t_sentence *sentence, size_t i)
{
	int	pipe_fds[2];

	if ((sentence->commands[i].redirect_type & OUTPUT_REDIRS) != 0)
	{
		if ((sentence->commands[i + 1].redirect_type
				& INPUT_REDIRS) == 0)
		{
			sentence->commands[i + 1].in_name = ft_strdup(
					sentence->commands[i].out_name);
			sentence->commands[i + 1].redirect_type
				|= TOKEN_TYPE_REDIRECT_INPUT;
		}
	}
	else
	{
		pipe(pipe_fds);
		sentence->commands[i].output_fd = pipe_fds[1];
		sentence->commands[i + 1].input_fd = pipe_fds[0];
	}
}
