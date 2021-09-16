/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:12 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_sentence		sentence;

	(void)argc;
	(void)argv;
	init_minishell_data();
	copy_env_variables(env);
	tr = init_token_reader();
	tr = read_tokens("echo hola | wc | wc");
	exp = expand_tokens(&tr);
	sentence = parse_sentence(&exp);
	execute_sentence(&sentence);
	return (0);
}
