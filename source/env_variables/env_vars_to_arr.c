/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:23:07 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/08 09:09:37 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

static size_t	count_env()
{
	size_t	i;
	size_t			count;
	t_env_variable	*var;

	count = 0;
	var = (t_env_variable *)&g_minishell_data;
	i = 0;
	while (i < g_minishell_data.default_env_var_count)
	{
		if (var[i].is_local == 0)
			count++;
		i++;
	}
	i = 0;
	var = g_minishell_data.extra_variables;
	while (i < g_minishell_data.extra_variables_size)
	{
		if (var[i].is_local == 0)	
			count++;
		i++;
	}

	return (count);
}

static void	copy_extra_variables(char **env)
{
	t_env_variable	*var;
	size_t			i;

	i = 0;
	var = g_minishell_data.extra_variables;
	while (i < g_minishell_data.extra_variables_size)
	{
		if (var[i].is_local == 0 && var[i].value != NULL)
			env[i] = envvar_to_str(&var[i]);
		i++;
	}
}

static void	copy_default_variables(char **env)
{
	t_env_variable	*var;
	size_t			i;

	i = 0;
	var = (t_env_variable *)&g_minishell_data;
	while (i < g_minishell_data.default_env_var_count)
	{
		if (var[i].is_local == 0 && var[i].value != NULL)
			env[i + g_minishell_data.extra_variables_size] = envvar_to_str(&var[i]);
		i++;
	}
}

char	**env_vars_to_arr(void)
{
	size_t			size_of_env;
	char			**env;

	size_of_env = count_env();
	env = malloc(sizeof(*env) * (size_of_env + 1));
	env[size_of_env] = NULL;
	copy_extra_variables(env);
	copy_default_variables(env);
	return (env);
}
