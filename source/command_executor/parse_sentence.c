/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sentence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:38:38 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/28 11:29:59 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"

t_sentence	parse_sentence(t_token_reader *tr)
{
	t_sentence	sentence;

	sentence = init_sentence();
	parse_commands_of_sentence(&sentence, tr);
	open_pipes(&sentence);
	return (sentence);
}
