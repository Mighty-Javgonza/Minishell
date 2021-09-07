/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:06:27 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 15:28:27 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

t_env_variable	*find_env_var(char *name)
{
	t_env_variable	*search;

	search = find_default_var(name);
	if (search != NULL)
		return (search);
	search = find_extra_var(name);
	return (search);
}
