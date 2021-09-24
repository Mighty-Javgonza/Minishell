/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 04:30:09 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_command		command;

	(void)argc;
	(void)argv;
	init_minishell_data();
	copy_env_variables(env);
	tr = read_tokens("echo hola < cat > hola");
	exp = expand_tokens(&tr);
	command = init_command();
	command.tr = get_tokens_of_command(&exp, 0);
	set_redirect_type(&command);
	set_redirect_names(&command);
	if (!streq(command.in_name, "cat") || !streq(command.out_name, "hola"))
		return (-1);
	return (0);
}
