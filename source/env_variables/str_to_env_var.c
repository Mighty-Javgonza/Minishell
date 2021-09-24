/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:18:44 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:36 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

t_env_variable	str_to_env_var(char *var)
{
	t_env_variable	env_var;
	char			**split;

	env_var.name = NULL;
	if (var == NULL)
		return (env_var);
	split = ft_split(var, '=');
	if (split[1] == NULL)
	{
		ft_freearray(split);
		return (env_var);
	}
	env_var.name = split[0];
	env_var.value = split[1];
	env_var.is_local = 1;
	free(split);
	return (env_var);
}
