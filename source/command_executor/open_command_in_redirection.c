/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_command_in_redirection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:06:15 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/03 08:42:40 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

void	open_command_in_redirection(t_sentence *sentence, size_t i)
{
	int		fd;
	char	*file;

	file = sentence->commands[i].in_name;
	fd = open(file, O_RDONLY);
	sentence->commands[i].input_fd = fd;
}
