/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/15 09:07:51 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	char	*args[3];
	char	start_wd[2000];
	char	end_wd[2000];

	(void)argc;
	(void)argv;
	init_minishell_data();
	copy_env_variables(env);
	getcwd(start_wd, 2000);
	args[0] = "cd";
	args[1] = "..";
	args[2] = NULL;
	execute_command_string_form(args[0], args);
	getcwd(end_wd, 2000);
	if (streq(start_wd, end_wd))
		return (-1);
	return (0);
}
