/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_of_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:04:44 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/15 10:28:09 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include "../../libft/incs/libft.h"

t_token_reader	get_tokens_of_command(t_token_reader *exp, size_t start_token)
{
	t_token_reader	tr;
	size_t			token_count;
	size_t			i;

	tr = init_token_reader();
	i = start_token;
	while (i < exp->token_count && exp->tokens[i].type == TOKEN_TYPE_NORMAL)
		i++;
	token_count = i - start_token;
	tr.token_count = token_count;
	tr.tokens = malloc(sizeof(*tr.tokens) * (tr.token_count));
	ft_memmove(tr.tokens, exp->tokens + start_token, sizeof(*tr.tokens) * tr.token_count);
	return (tr);
}
