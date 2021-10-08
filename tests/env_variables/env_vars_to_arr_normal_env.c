/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/07 08:59:50 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

#define VAR "HOLA=sisi"
#define VAR2 "HOLA2=nono"

int	main(int argc, char **argv, char **env)
{
	char	**new_env;

	(void)argv;
	(void)argc;
	init_minishell_data();
	copy_env_variables(env);
	load_env_variable(VAR);
	load_env_variable(VAR2);
	new_env = env_vars_to_arr();
	if (!streq("TERM_PROGRAM=iTerm.app", new_env[0]))
		return (-1);
	return (0);
}
