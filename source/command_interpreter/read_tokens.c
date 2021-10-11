/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:14:39 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 14:59:01 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

t_token_reader	read_tokens(char *string)
{
	t_token_reader	tr;
	t_token			token;
	char			*token_start;

	tr = init_token_reader();
	token = init_token();
	token = get_first_token_from_string(string);
	if (token.value != NULL)
		add_token(&tr, token);
	token_start = token.end;
	while (token.value != NULL && *token_start != '\0')
	{
		token = init_token();
		token = get_first_token_from_string(token_start + 1);
		token_start = token.end;
		if (token.value != NULL)
			add_token(&tr, token);
	}
	return (tr);
}
