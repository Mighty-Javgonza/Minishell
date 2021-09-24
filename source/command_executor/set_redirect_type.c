/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:19:55 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 05:47:42 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>

void	set_redirect_type(t_command *command)
{
	size_t	i;
	int		t;

	i = 0;
	while (i < command->tr.token_count)
	{
		t = command->tr.tokens[i].type;
		if (t != TOKEN_TYPE_NORMAL)
		{
			if (t == TOKEN_TYPE_REDIRECT_OUTPUT)
				command->redirect_type &= ~TOKEN_TYPE_REDIRECT_OUTPUT_APPEND;
			if (t == TOKEN_TYPE_REDIRECT_OUTPUT_APPEND)
				command->redirect_type &= ~TOKEN_TYPE_REDIRECT_OUTPUT;
			command->redirect_type |= t;
		}
		i++;
	}
}
