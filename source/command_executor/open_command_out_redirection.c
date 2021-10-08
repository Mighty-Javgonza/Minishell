/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_command_out_redirection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:36:42 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/01 11:07:33 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <fcntl.h>
#include <sys/stat.h>

void	open_command_out_redirection(t_sentence *sentence, size_t i)
{
	int		fd;
	char	*file;

	file = sentence->commands[i].out_name;
	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	sentence->commands[i].output_fd = fd;
}
