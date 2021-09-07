/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_var_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:00:23 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 14:08:33 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

void	free_env_var_list(t_env_variable *old_vars)
{
	size_t	i;

	i = 0;
	while (old_vars[i].name != NULL)
	{
		free(old_vars[i].name);
		free(old_vars[i].value);
		i++;
	}
	free(old_vars);
}
