/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_default_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:24:21 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 12:45:30 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

t_env_variable	*find_default_var(t_env_var_list *env_vars, char *name)
{
	size_t			i;
	t_env_variable	*list;

	list = (t_env_variable *)env_vars;
	i = 0;
	while (i < env_vars->default_env_var_count)
	{
		if (streq(list[i].name, name))
			return (&list[i]);
		i++;
	}
	return (NULL);
}
