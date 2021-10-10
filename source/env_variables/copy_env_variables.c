/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:15:57 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:28 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

//TODO:Cambiar al main
t_minishell_data	g_minishell_data;

void	copy_env_variables(char **env)
{
	size_t	i;
	char	**var_split;

	i = 0;
	while (env[i] != NULL)
	{
		var_split = ft_split(env[i], '=');
		load_env_variable(env[i]);
		export_var(var_split[0]);
		ft_freearray(var_split);
		i++;
	}
}
