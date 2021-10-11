/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sentence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:05:00 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:58:19 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include "../command_interpreter/command_interpreter.h"
#include "../../libft/incs/libft.h"

int	execute_sentence(t_sentence *sentence, t_env_var_list *env_vars)
{
	size_t	i;

	i = 0;
	while (i < sentence->command_count)
	{
		if (sentence->commands[i].gets_executed)
		{
			execute_command(&sentence->commands[i], env_vars);
		}
		i++;
	}
	return (0);
}
