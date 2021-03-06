/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect_names.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 04:21:09 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:20 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>

static t_token	*first_token_after_last_token_of_type(t_token_reader *tr,
			unsigned int type)
{
	size_t	i;
	t_token	*token;

	if (type == 0)
		return (NULL);
	i = tr->token_count;
	while (i > 0)
	{
		token = &tr->tokens[i - 1];
		if (token->type == type)
			if (i != tr->token_count)
				return (&tr->tokens[i]);
		i--;
	}
	return (NULL);
}

void	set_redirect_names(t_command *command)
{
	t_token	*token;

	token = first_token_after_last_token_of_type(
			&command->tr, command->redirect_type & OUTPUT_REDIRS);
	if (token != NULL)
		command->out_name = token->value;
	token = first_token_after_last_token_of_type(
			&command->tr, command->redirect_type & INPUT_REDIRS);
	if (token != NULL)
		command->in_name = token->value;
}
