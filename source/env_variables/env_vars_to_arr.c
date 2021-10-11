/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:23:07 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:19:07 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

static size_t	count_env(t_env_var_list *env_vars)
{
	size_t			i;
	size_t			count;
	t_env_variable	*var;

	count = 0;
	var = (t_env_variable *)env_vars;
	i = 0;
	while (i < env_vars->default_env_var_count)
	{
		if (var[i].value != NULL && var[i].is_local == 0)
			count++;
		i++;
	}
	i = 0;
	var = env_vars->extra_variables;
	while (i < env_vars->extra_variables_size)
	{
		if (var[i].value != NULL && var[i].is_local == 0)
			count++;
		i++;
	}
	return (count);
}

static size_t	copy_extra_variables(t_env_var_list *env_vars, char **env)
{
	t_env_variable	*var;
	size_t			i;
	size_t			loaded_vars;

	i = 0;
	loaded_vars = 0;
	var = env_vars->extra_variables;
	while (i < env_vars->extra_variables_size)
	{
		if (var[i].is_local == 0 && var[i].value != NULL)
		{
			env[loaded_vars] = envvar_to_str(&var[i]);
			loaded_vars++;
		}
		i++;
	}
	return (loaded_vars);
}

static void	copy_default_variables(t_env_var_list *env_vars, char **env,
			size_t loaded_vars)
{
	t_env_variable	*var;
	size_t			i;

	i = 0;
	var = (t_env_variable *)env_vars;
	while (i < env_vars->default_env_var_count)
	{
		if (var[i].is_local == 0 && var[i].value != NULL)
		{
			env[loaded_vars] = envvar_to_str(&var[i]);
			loaded_vars++;
		}
		i++;
	}
}

char	**env_vars_to_arr(t_env_var_list *env_vars)
{
	size_t			size_of_env;
	char			**env;
	size_t			loaded_vars;

	if (env_vars == NULL)
		return (NULL);
	size_of_env = count_env(env_vars);
	env = malloc(sizeof(*env) * (size_of_env + 1));
	env[size_of_env] = NULL;
	loaded_vars = copy_extra_variables(env_vars, env);
	copy_default_variables(env_vars, env, loaded_vars);
	return (env);
}
