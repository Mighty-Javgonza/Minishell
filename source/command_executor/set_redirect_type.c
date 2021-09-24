/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:19:55 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 04:14:21 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>

void	set_redirect_type(t_command *command)
{
	size_t	i;
	t_token	*token;

	i = 0;
	while (i < command->tr.token_count)
	{
		token = &command->tr.tokens[i];
		if (token->type != TOKEN_TYPE_NORMAL)
			command->redirect_type |= token->type;
		i++;
	}
}
