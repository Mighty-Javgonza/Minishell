/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:33:48 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 12:40:01 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

static void	print_one_var(t_env_variable var)
{
	if (var.is_local)
		return ;
	printf("%s", var.name);
	printf("=");
	printf("%s\n", var.value);
}

void	print_env_vars(t_env_var_list *env_vars)
{
	size_t			i;
	t_env_variable	*casted_env_vars;

	casted_env_vars = (t_env_variable *)env_vars;
	i = 0;
	while (i < env_vars->default_env_var_count)
	{
		if (casted_env_vars[i].name != NULL)
			print_one_var(casted_env_vars[i]);
		i++;
	}
	i = 0;
	while (i < env_vars->extra_variables_size)
	{
		print_one_var(env_vars->extra_variables[i]);
		i++;
	}
}
