/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:48:59 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:00:39 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

void	export_var(t_env_var_list *env_vars, char *name)
{
	t_env_variable	*search;

	search = find_env_var(env_vars, name);
	if (search == NULL)
		return ;
	search->is_local = 0;
}
