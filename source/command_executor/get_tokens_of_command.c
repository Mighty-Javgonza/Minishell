/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_of_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:04:44 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:56:55 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include "../../libft/incs/libft.h"

static int	is_non_ending_token(t_token *token)
{
	int	t;

	t = token->type;
	return (t == TOKEN_TYPE_NORMAL
		|| t == TOKEN_TYPE_REDIRECT_OUTPUT
		|| t == TOKEN_TYPE_REDIRECT_INPUT
		|| t == TOKEN_TYPE_REDIRECT_OUTPUT_APPEND
		|| t == TOKEN_TYPE_REDIRECT_INPUT_DELIMITER);
}

t_token_reader	get_tokens_of_command(t_token_reader *exp, size_t start_token)
{
	t_token_reader	tr;
	size_t			token_count;
	size_t			i;

	tr = init_token_reader();
	i = start_token;
	if (exp->tokens[start_token].type == TOKEN_TYPE_PIPE)
		return (tr);
	while (i < exp->token_count && is_non_ending_token(&exp->tokens[i]))
		i++;
	token_count = i - start_token;
	if (token_count + start_token < exp->token_count)
		token_count++;
	tr.token_count = token_count;
	tr.tokens = malloc(sizeof(*tr.tokens) * (tr.token_count));
	ft_memmove(tr.tokens, exp->tokens + start_token,
		sizeof(*tr.tokens) * tr.token_count);
	return (tr);
}
