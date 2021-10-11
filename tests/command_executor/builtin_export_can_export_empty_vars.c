/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:22:09 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int	main(int argc, char **argv, char **env)
{
	char			*args_to_export[3];
	t_env_variable	*env_var;
	t_env_var_list	env_vars;

	(void)argv;
	(void)argc;
	init_minishell_data();
	env_vars = init_env_var_list();
	copy_env_variables(&env_vars, env);
	args_to_export[0] = "does not matter";
	args_to_export[1] = "hola";
	args_to_export[2] = NULL;
	builtin_export(args_to_export, &env_vars);
	env_var = find_env_var(&env_vars, "hola");
	if (env_var == NULL)
		return (-1);
	return (0);
}
