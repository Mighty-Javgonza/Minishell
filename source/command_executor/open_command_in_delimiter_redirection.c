/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:47:45 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 18:06:00 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <unistd.h>

void	open_command_in_delimiter_redirection(t_sentence *sentence,
		size_t i)
{
	int	pipe_fds[2];

	pipe(pipe_fds);
	read_until_line(pipe_fds[1], sentence->commands[i].in_name);
	close(pipe_fds[1]);
	sentence->commands[i].input_fd = pipe_fds[0];
}
