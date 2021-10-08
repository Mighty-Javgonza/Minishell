/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/03 11:15:29 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int	main(int argc, char **argv, char **env)
{
	char			*args_to_export[3];
	t_env_variable	*env_var;

	(void)argv;
	(void)argc;
	init_minishell_data();
	copy_env_variables(env);
	args_to_export[0] = "does not matter";
	args_to_export[1] = "hola";
	args_to_export[2] = NULL;
	builtin_export(args_to_export);
	env_var = find_env_var("hola");
	if (env_var == NULL)
		return (-1);
	return (0);
}
