/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:36:43 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main()
{
	char			*args[2];
	int				res;
	t_env_var_list	env_vars;

	env_vars = init_env_var_list();
	load_env_variable(&env_vars, "PATH=hola");
	args[0] = "hello_world.out";
	args[1] = NULL;
	res = execute_command_string_form("hello_world.out", args, &env_vars);
	if (res != 0)
		return (-1);
	return (0);
}
