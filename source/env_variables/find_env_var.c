/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:06:27 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 12:44:46 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

t_env_variable	*find_env_var(t_env_var_list *env_vars, char *name)
{
	t_env_variable	*search;

	search = find_default_var(env_vars, name);
	if (search != NULL)
		return (search);
	search = find_extra_var(env_vars, name);
	return (search);
}
