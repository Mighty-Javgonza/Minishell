/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sentence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:38:38 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/05 12:12:52 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"
#include "../utils/utils.h"

t_sentence	parse_sentence(t_token_reader *tr)
{
	t_sentence	sentence;

	sentence = init_sentence();
	if (streq(tr->tokens[0].value, "|"))
	{
		printf("Parse error near '|'\n");
		return (sentence);
	}
	parse_commands_of_sentence(&sentence, tr);
	open_pipes(&sentence);
	return (sentence);
}
