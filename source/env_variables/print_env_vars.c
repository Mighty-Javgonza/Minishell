/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:33:48 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 13:55:36 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

static void	print_one_var(t_env_variable var)
{
	printf("%s", var.name);
	printf("=");
	printf("%s\n", var.value);
}

void	print_env_vars()
{
	size_t			i;
	t_env_variable	*casted_env_vars;

	casted_env_vars = (t_env_variable *)&g_minishell_data;
	i = 0;
	while (i < g_minishell_data.default_env_var_count)
	{
		if (casted_env_vars[i].name != NULL)
			print_one_var(casted_env_vars[i]);
		i++;
	}
	i = 0;
	while (i < g_minishell_data.extra_variables_size)
	{
		print_one_var(g_minishell_data.extra_variables[i]);
		i++;
	}	
}
