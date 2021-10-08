/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/03 08:38:25 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main()
{
	char	*args[2];
	int		res;

	init_minishell_data();
	load_env_variable("PATH=");
	args[0] = "hello_world.out";
	args[1] = NULL;
	res = execute_command_string_form("hello_world.out", args);
	if (res != 0)
		return (-1);
	return (0);
}
