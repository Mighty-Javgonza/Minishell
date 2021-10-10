/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_default_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:24:21 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:30 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

t_env_variable	*find_default_var(char *name)
{
	size_t			i;
	t_env_variable	*list;

	list = (t_env_variable *)&g_minishell_data;
	i = 0;
	while (i < g_minishell_data.default_env_var_count)
	{
		if (streq(list[i].name, name))
			return (&list[i]);
		i++;
	}
	return (NULL);
}
