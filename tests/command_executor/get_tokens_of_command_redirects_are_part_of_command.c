/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/23 10:43:54 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_token_reader	newtr;

	(void)argc;
	(void)argv;
	init_minishell_data();
	copy_env_variables(env);
	tr = read_tokens("echo hola < cat");
	exp = expand_tokens(&tr);
	newtr = get_tokens_of_command(&exp, 0);
	if (newtr.token_count != 4)
		return (-1);
	return (0);
}
