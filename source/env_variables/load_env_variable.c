/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_env_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:21:55 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:49:14 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

//TODO: Hacer todas las variables default

static void	set_def_var(char **split)
{
	set_term_program(split[0], split[1]);
	set_term(split[0], split[1]);
	set_shell(split[0], split[1]);
	set_path(split[0], split[1]);
	set_home(split[0], split[1]);
	set_pwd(split[0], split[1]);
}

void	load_env_variable(char *var)
{
	char			**split;
	t_env_variable	*existing_var;

	if (var == NULL)
		return ;
	split = ft_split(var, '=');
	if (split[1] == NULL)
	{
		ft_freearray(split);
		return ;
	}
	set_def_var(split);
	existing_var = find_default_var(split[0]);
	if (existing_var == NULL)
	{
		existing_var = find_extra_var(split[0]);
		if (existing_var == NULL)
			load_extra_variable(var);
		else
			set_variable(split[0], split[1]);
	}
	ft_freearray(split);
}
