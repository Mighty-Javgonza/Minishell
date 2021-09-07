/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_env_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:21:55 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 13:07:43 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

//TODO: Hacer todas las variables

void	load_env_variable(char *var)
{
	char	**split;

	if (var == NULL)
		return ;
	split = ft_split(var, '=');
	if (split[1] == NULL)
	{
		ft_freearray(split);
		return ;
	}
	set_term_program(split[0], split[1]);
	set_term(split[0], split[1]);
	set_shell(split[0], split[1]);
	ft_freearray(split);
}
