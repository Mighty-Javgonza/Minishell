/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:28:52 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	char	*args[3];
	char	start_wd[2000];
	char	end_wd[2000];
	t_env_var_list	env_vars;

	(void)argc;
	(void)argv;
	env_vars = init_env_var_list();
	copy_env_variables(&env_vars, env);
	getcwd(start_wd, 2000);
	args[0] = "cd";
	args[1] = "..";
	args[2] = NULL;
	execute_command_string_form(args[0], args, &env_vars);
	getcwd(end_wd, 2000);
	if (streq(start_wd, end_wd))
		return (-1);
	return (0);
}
