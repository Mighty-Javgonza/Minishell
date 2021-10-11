/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_extra_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:02:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:37:22 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

void	load_extra_variable(t_env_var_list *env_vars, char *new_var)
{
	t_env_variable	*old_vars;
	size_t			i;

	old_vars = env_vars->extra_variables;
	env_vars->extra_variables = malloc(
			sizeof(*env_vars->extra_variables)
			* (env_vars->extra_variables_size + 2));
	i = 0;
	while (old_vars[i].name != NULL)
	{
		env_vars->extra_variables[i].name = ft_strdup(old_vars[i].name);
		env_vars->extra_variables[i].value
			= ft_strdup(old_vars[i].value);
		env_vars->extra_variables[i].is_local = 0;
		i++;
	}
	env_vars->extra_variables[i] = str_to_env_var(new_var);
	env_vars->extra_variables[i + 1].name = NULL;
	env_vars->extra_variables_size++;
	free_env_var_list(old_vars);
}
