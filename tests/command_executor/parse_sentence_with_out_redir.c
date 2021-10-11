/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:50:18 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_sentence		sentence;
	t_env_var_list	env_vars;

	(void)argc;
	(void)argv;
	env_vars = init_env_var_list();
	copy_env_variables(&env_vars, env);
	tr = init_token_reader();
	tr = read_tokens("echo hola > turut");
	exp = expand_tokens(&env_vars, &tr);
	sentence = init_sentence();
	parse_commands_of_sentence(&sentence, &exp);
	if (sentence.commands[0].tr.token_count != 4)
		return (-1);
	return (0);
}
