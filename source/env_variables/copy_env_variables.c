/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:21:23 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:21:25 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

t_minishell_data	g_minishell_data;

void	copy_env_variables(t_env_var_list *env_vars, char **env)
{
	size_t	i;
	char	**var_split;

	i = 0;
	while (env[i] != NULL)
	{
		var_split = ft_split(env[i], '=');
		load_env_variable(env_vars, env[i]);
		export_var(env_vars, var_split[0]);
		ft_freearray(var_split);
		i++;
	}
}
