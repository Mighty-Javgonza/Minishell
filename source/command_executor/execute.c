/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:21:14 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:16 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>

void	execute(char *command)
{
	t_sentence		sentence;
	t_token_reader	tr;
	t_token_reader	exp;

	tr = init_token_reader();
	tr = read_tokens(command);
	if (tr.token_count == 0)
	{
		destroy_token_reader(&tr);
		return ;
	}
	exp = expand_tokens(&tr);
	sentence = parse_sentence(&exp);
	execute_sentence(&sentence);
	destroy_sentence(&sentence);
	destroy_token_reader(&tr);
	destroy_token_reader(&exp);
}
