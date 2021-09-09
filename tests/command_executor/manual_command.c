/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/09 12:55:52 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main()
{
#if 0
	char	*args[2];
	int		res;
	char	*command;

	command = readline("🐙>");
	args[0] = "hello_world.out";
	args[1] = NULL;
	res = execute_command(command, args);
	if (res != 0)
		return (-1);
#endif
	return (0);
}
