/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:15:57 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:31 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

//TODO:Cambiar al main
t_minishell_data	g_minishell_data;

void	copy_env_variables(char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		load_env_variable(env[i]);
		i++;
	}
}
