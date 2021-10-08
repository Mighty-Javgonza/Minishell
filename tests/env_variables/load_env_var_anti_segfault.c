/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/03 10:53:57 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init_minishell_data();
	load_env_variable("Hola");
	if (streq(env[1] + ft_strlen("TERM="), g_minishell_data.term.name))
		return (-1);
	load_env_variable(NULL);
	return (0);
}
