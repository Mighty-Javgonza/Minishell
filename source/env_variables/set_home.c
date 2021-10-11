/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:25:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:30:27 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

void	set_home(t_env_var_list *env_vars, char *name, char *value)
{
	if (streq(name, "HOME"))
	{
		env_vars->home.value = ft_strdup(value);
		env_vars->home.name = ft_strdup("HOME");
		env_vars->home.is_local = 0;
	}
}
