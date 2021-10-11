/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sentence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:38:38 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:04:54 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"
#include "../utils/utils.h"

t_sentence	parse_sentence(t_token_reader *tr)
{
	t_sentence	sentence;
	int			error;

	sentence = init_sentence();
	if (tr->tokens[0].type == TOKEN_TYPE_PIPE
		|| tr->tokens[tr->token_count - 1].type == TOKEN_TYPE_PIPE)
	{
		printf("Parse error near '|'\n");
		return (sentence);
	}
	error = parse_commands_of_sentence(&sentence, tr);
	if (error != 0)
	{
		printf("Parse error \n");
		destroy_sentence(&sentence);
		sentence = init_sentence();
		return (sentence);
	}
	open_pipes(&sentence);
	return (sentence);
}
