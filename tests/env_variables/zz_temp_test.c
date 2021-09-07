/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 14:09:18 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	init_minishell_data();
	copy_env_variables(env);
	load_extra_variable("CUSTOM=1");
	load_extra_variable("VICMARTI=Esta mirando");
	load_extra_variable("JAVGONZA=Esta tecleando");
	free_env_var_list(g_minishell_data.extra_variables);
	system("leaks zz_temp_test.test");
	return (0);
}
