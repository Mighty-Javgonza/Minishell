/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:15:25 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 15:18:03 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

t_env_variable	*set_variable(char *name, char *value)
{
	t_env_variable	*found_var;

	found_var = find_env_var(name);
	free(found_var->value);
	found_var->value = ft_strdup(value);
	return (found_var);
}
