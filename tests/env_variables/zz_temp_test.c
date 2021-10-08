/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/07 08:51:35 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

#define VAR "HOLA=sisi"
#define VAR2 "HOLA2=nono"

int	main()
{
	char	**new_env;

	init_minishell_data();
	load_env_variable(VAR);
	load_env_variable(VAR2);
	export_var("HOLA");
	export_var("HOLA2");
	new_env = env_vars_to_arr();
	if (!streq(VAR2, new_env[1]))
		return (-1);
	return (0);
}
