/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:35:27 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:27:48 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

static void	open_command_pipe(t_sentence *sentence, size_t i)
{
	int	pipe_fds[2];

	pipe(pipe_fds);
	sentence->commands[i].output_fd = pipe_fds[1];
	sentence->commands[i + 1].input_fd = pipe_fds[0];
}

static void	open_command_out_redirection(t_sentence *sentence, size_t i)
{
	int		fd;
	char	*file;

	file = sentence->commands[i].out_name;
	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	sentence->commands[i].output_fd = fd;
}

static void	open_command_out_append_redirection(t_sentence *sentence, size_t i)
{
	int		fd;
	char	*file;

	file = sentence->commands[i].out_name;
	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
	sentence->commands[i].output_fd = fd;
}

static void	open_command_in_redirection(t_sentence *sentence, size_t i)
{
	int		fd;
	char	*file;

	file = sentence->commands[i].in_name;
	fd = open(file, O_RDONLY);
	sentence->commands[i].input_fd = fd;
}

void	open_pipes(t_sentence *sentence)
{
	size_t		i;
	int			redir;

	i = 0;
	while (i < sentence->command_count)
	{
		redir = sentence->commands[i].redirect_type;
		if ((redir & TOKEN_TYPE_PIPE) != 0)
			open_command_pipe(sentence, i);
		else if ((redir & TOKEN_TYPE_REDIRECT_OUTPUT) != 0)
			open_command_out_redirection(sentence, i);
		else if ((redir & TOKEN_TYPE_REDIRECT_OUTPUT_APPEND) != 0)
			open_command_out_append_redirection(sentence, i);
		if (sentence->commands[i].input_fd != STDIN_FILENO && (redir
				& TOKEN_TYPE_REDIRECT_INPUT) != 0)
			open_command_in_redirection(sentence, i);
		i++;
	}
}
