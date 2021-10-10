/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:15:25 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/08 11:23:06 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

t_env_variable	*set_variable(char *name, char *value)
{
	t_env_variable	*found_var;
	char			*new_var;
	char			*tmp;

	found_var = find_env_var(name);
	if (found_var != NULL)
	{
		free(found_var->value);
		found_var->value = ft_strdup(value);
	}
	else
	{
		tmp = ft_strjoin(name, "=");
		new_var = ft_strjoin(name, value);
		load_env_variable(new_var);
		free(tmp);
		free(new_var);
	}
	return (found_var);
}
