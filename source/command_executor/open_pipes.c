/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:35:27 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/16 10:03:50 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>

void	open_pipes(t_sentence *sentence)
{
	size_t	i;
	int	pipe_fds[2];

	i = 0;
	while (i < sentence->command_count)
	{
		if (sentence->commands[i].redirect_type == TOKEN_TYPE_PIPE)
		{
			pipe(pipe_fds);
			sentence->commands[i].output_fd = pipe_fds[1];
			sentence->commands[i + 1].input_fd = pipe_fds[0];
		}
		i++;
	}
}
