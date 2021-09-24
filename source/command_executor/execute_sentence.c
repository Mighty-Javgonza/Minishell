/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sentence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:05:00 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:25 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include "../command_interpreter/command_interpreter.h"

int	execute_sentence(t_sentence *sentence)
{
	size_t	i;
	int		in_fd;
	int		out_fd;

	in_fd = dup(STDIN_FILENO);
	out_fd = dup(STDOUT_FILENO);
	i = 0;
	while (i < sentence->command_count)
	{
		if (sentence->commands[i].gets_executed)
			execute_command(&sentence->commands[i]);
		i++;
	}
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(in_fd);
	close(out_fd);
	return (0);
}
