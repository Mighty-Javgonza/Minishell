/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_extra_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:02:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:32 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

void	load_extra_variable(char *new_var)
{
	t_env_variable	*old_vars;
	size_t			i;

	old_vars = g_minishell_data.extra_variables;
	g_minishell_data.extra_variables = malloc(
			sizeof(*g_minishell_data.extra_variables)
			* (g_minishell_data.extra_variables_size + 2));
	i = 0;
	while (old_vars[i].name != NULL)
	{
		g_minishell_data.extra_variables[i].name = ft_strdup(old_vars[i].name);
		g_minishell_data.extra_variables[i].value
			= ft_strdup(old_vars[i].value);
		g_minishell_data.extra_variables[i].is_local = 0;
		i++;
	}
	g_minishell_data.extra_variables[i] = str_to_env_var(new_var);
	g_minishell_data.extra_variables[i + 1].name = NULL;
	g_minishell_data.extra_variables_size++;
	free_env_var_list(old_vars);
}
