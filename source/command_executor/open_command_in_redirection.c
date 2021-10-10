/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_command_in_redirection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:06:15 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/08 10:05:31 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

void	open_command_in_redirection(t_command *command)
{
	int		fd;

	fd = open(command->in_name, O_RDONLY);
	command->input_fd = fd;
}
