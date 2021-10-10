/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/05 12:01:16 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int	main(int argc, char **argv, char **env)
{
	t_sentence		sentence;
	t_token_reader	tr;
	t_token_reader	exp;

	(void)argv;
	(void)argc;
	init_minishell_data();
	copy_env_variables(env);
	tr = read_tokens("|");
	exp = expand_tokens(&tr);
	sentence = parse_sentence(&exp);
	if (sentence.command_count != 0)
		return (-1);
	return (0);
}
