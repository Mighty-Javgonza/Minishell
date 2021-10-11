/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:51:42 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_command		command;
	t_env_var_list	env_vars;

	(void)argc;
	(void)argv;
	env_vars = init_env_var_list();
	copy_env_variables(&env_vars, env);
	tr = read_tokens("echo hola > cat >> hola");
	exp = expand_tokens(&env_vars, &tr);
	command = init_command();
	command.tr = get_tokens_of_command(&exp, 0);
	set_redirect_type(&command);
	if (command.redirect_type != TOKEN_TYPE_REDIRECT_OUTPUT_APPEND)
		return (-1);
	return (0);
}
