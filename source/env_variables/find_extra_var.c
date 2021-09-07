/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extra_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:26:09 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 15:26:50 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

t_env_variable	*find_extra_var(char *name)
{
	t_env_variable	*list;
	size_t			i;

	list = g_minishell_data.extra_variables;
	i = 0;
	while (i < g_minishell_data.extra_variables_size)
	{
		if (streq(list[i].name, name))
			return (&list[i]);
		i++;
	}
	return (NULL);
}
