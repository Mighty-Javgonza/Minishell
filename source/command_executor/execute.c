/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:21:14 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:49:10 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>

void	execute(char *command, t_env_var_list *env_vars)
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
	exp = expand_tokens(env_vars, &tr);
	sentence = parse_sentence(&exp);
	execute_sentence(&sentence, env_vars);
	destroy_sentence(&sentence);
	destroy_token_reader(&tr);
	destroy_token_reader(&exp);
}
