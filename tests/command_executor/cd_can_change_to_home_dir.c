/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/15 09:07:35 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	char	*args[2];
	char	wd[2000];

	(void)argc;
	(void)argv;
	init_minishell_data();
	copy_env_variables(env);
	args[0] = "cd";
	args[1] = NULL;
	execute_command_string_form(args[0], args);
	getcwd(wd, 2000);
	if (!streq(wd, g_minishell_data.home.value))
		return (-1);
	return (0);
}
