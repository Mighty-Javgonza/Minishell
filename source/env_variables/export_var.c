/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:48:59 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:32 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

void	export_var(char *name)
{
	t_env_variable	*search;

	search = find_env_var(name);
	if (search == NULL)
		return ;
	search->is_local = 0;
}
