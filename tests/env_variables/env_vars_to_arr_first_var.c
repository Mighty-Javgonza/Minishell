/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/07 09:00:48 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

#define VAR "HOLA=sisi"

int	main()
{
	char	**new_env;

	init_minishell_data();
	load_env_variable(VAR);
	export_var("HOLA");
	new_env = env_vars_to_arr();
	if (!streq(VAR, new_env[0]))
		return (-1);
	return (0);
}
