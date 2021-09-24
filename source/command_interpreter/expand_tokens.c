/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:44:02 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:32:00 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include <stdio.h>

t_token_reader	expand_tokens(t_token_reader *tr)
{
	size_t			i;
	t_token_reader	exp;

	exp = init_token_reader();
	i = 0;
	while (i < tr->token_count)
	{
		add_expansion_to_reader(&exp, &tr->tokens[i]);
		i++;
	}
	return (exp);
}
