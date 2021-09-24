/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:27:04 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 04:19:26 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <unistd.h>

t_command	init_command()
{
	t_command	rvalue;

	rvalue = (t_command)
	{
		.tr = init_token_reader(),
		.output_fd = STDOUT_FILENO,
		.input_fd = STDIN_FILENO,
		.redirect_type = 0,
		.gets_executed = 1,
		.out_name = NULL,
		.in_name = NULL,
	};
	return (rvalue);
}