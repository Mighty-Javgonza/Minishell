/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:35:27 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/08 10:29:43 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include "../../libft/incs/libft.h"

void	open_pipes(t_sentence *sentence)
{
	size_t		i;
	int			redir;

	i = 0;
	while (i < sentence->command_count)
	{
		redir = sentence->commands[i].redirect_type;
		if ((redir & TOKEN_TYPE_REDIRECT_OUTPUT) != 0);
		else if ((redir & TOKEN_TYPE_REDIRECT_OUTPUT_APPEND) != 0);
		else if ((redir & TOKEN_TYPE_PIPE) != 0)
			open_command_pipe(sentence, i);
		if (sentence->commands[i].input_fd == STDIN_FILENO && (redir
				& TOKEN_TYPE_REDIRECT_INPUT) != 0);
		else if ((redir & TOKEN_TYPE_REDIRECT_INPUT_DELIMITER) != 0)
			open_command_in_delimiter_redirection(sentence, i);
		i++;
	}
}
