/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:18:44 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:34 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

t_env_variable	str_to_env_var(char *var)
{
	t_env_variable	env_var;
	char			**split;
	char			*var_name;

	env_var.name = NULL;
	if (var == NULL || *var == '\0')
		return (env_var);
	split = ft_split(var, '=');
	if (split[1] == NULL)
	{
		var_name = split[0];
		free(split);
		split = malloc(sizeof(*split) * 3);
		split[0] = var_name;
		split[1] = ft_strdup("");
		split[2] = NULL;
	}
	env_var.name = split[0];
	env_var.value = split[1];
	env_var.is_local = 1;
	free(split);
	return (env_var);
}
