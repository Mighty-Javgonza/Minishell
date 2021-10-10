/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_command_out_redirection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:36:42 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:19 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <fcntl.h>
#include <sys/stat.h>

void	open_command_out_redirection(t_command *command)
{
	int		fd;

	fd = open(command->out_name, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	command->output_fd = fd;
}
