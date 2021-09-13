/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:44:02 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/10 13:53:54 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"

t_token_reader	expand_tokens(t_token_reader *tr)
{
	t_token_reader	exp;
	(void)tr;

	exp = init_token_reader();
	return (exp);
}
