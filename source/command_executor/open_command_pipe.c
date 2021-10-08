/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_command_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:36:05 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/01 10:36:20 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <unistd.h>

void	open_command_pipe(t_sentence *sentence, size_t i)
{
	int	pipe_fds[2];

	pipe(pipe_fds);
	sentence->commands[i].output_fd = pipe_fds[1];
	sentence->commands[i + 1].input_fd = pipe_fds[0];
}
