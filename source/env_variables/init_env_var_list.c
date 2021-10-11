/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_var_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:25:39 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:19:25 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

t_env_var_list	init_env_var_list(void)
{
	t_env_var_list	rvalue;

	ft_memset(&rvalue, 0, sizeof(rvalue));
	rvalue.extra_variables = malloc(
			sizeof(*rvalue.extra_variables));
	rvalue.extra_variables->name = NULL;
	rvalue.extra_variables_size = 0;
	rvalue.default_env_var_count = 6;
	return (rvalue);
}
