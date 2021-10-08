/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sentence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:05:00 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/05 11:54:04 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include "../command_interpreter/command_interpreter.h"
#include "../../libft/incs/libft.h"

int	execute_sentence(t_sentence *sentence)
{
	size_t	i;

	i = 0;
	while (i < sentence->command_count)
	{
		if (sentence->commands[i].gets_executed)
		{
			execute_command(&sentence->commands[i]);
		}
		i++;
	}
	return (0);
}
