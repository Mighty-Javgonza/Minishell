/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:41:37 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:25 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include "../../libft/incs/libft.h"

void	add_token(t_token_reader *tr, t_token token)
{
	t_token	*old_tokens;

	old_tokens = tr->tokens;
	tr->tokens = malloc(sizeof(*tr->tokens) * (tr->token_count + 1));
	ft_memmove(tr->tokens, old_tokens, tr->token_count * sizeof(*tr->tokens));
	tr->tokens[tr->token_count] = token;
	tr->token_count++;
	if (old_tokens != NULL)
		free(old_tokens);
}
