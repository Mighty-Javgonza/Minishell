/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:23:33 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	char			*args[2];
	char			wd[2000];
	t_env_var_list	env_vars;

	(void)argc;
	(void)argv;
	env_vars = init_env_var_list();
	copy_env_variables(&env_vars, env);
	args[0] = "cd";
	args[1] = NULL;
	execute_command_string_form(args[0], args, &env_vars);
	getcwd(wd, 2000);
	if (!streq(wd, env_vars.home.value))
		return (-1);
	return (0);
}
