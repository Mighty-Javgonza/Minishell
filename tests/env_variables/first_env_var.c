/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/07 08:56:24 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init_minishell_data();
	load_env_variable(env[0]);
	if (!streq(env[0] + ft_strlen("TERM_PROGRAM="), g_minishell_data.term_program.value))
		return (-1);
	return (0);
}
