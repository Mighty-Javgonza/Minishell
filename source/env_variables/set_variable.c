/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:15:25 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:34:52 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

t_env_variable	*set_variable(t_env_var_list *env_vars, char *name, char *value)
{
	t_env_variable	*found_var;
	char			*new_var;
	char			*tmp;

	found_var = find_env_var(env_vars, name);
	if (found_var != NULL)
	{
		free(found_var->value);
		found_var->value = ft_strdup(value);
	}
	else
	{
		tmp = ft_strjoin(name, "=");
		new_var = ft_strjoin(name, value);
		load_env_variable(env_vars, new_var);
		free(tmp);
		free(new_var);
	}
	return (found_var);
}
