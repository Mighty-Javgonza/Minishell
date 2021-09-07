/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 15:40:23 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main(int argc, char **argv, char **env)
{
	t_env_variable	*var;

	(void)argc;
	(void)argv;
	(void)env;
	init_minishell_data();
	copy_env_variables(env);
	load_env_variable("CUSTOM=1");
	load_env_variable("CUSTOM=3");
	var = find_env_var("CUSTOM");
	if (!streq(var->value, "3"))
		return (-1);
	return (0);
}
