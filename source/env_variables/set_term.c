/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:25:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:33:21 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

void	set_term(t_env_var_list *env_vars, char *name, char *value)
{
	if (streq(name, "TERM"))
	{
		env_vars->term.value = ft_strdup(value);
		env_vars->term.name = ft_strdup("TERM");
		env_vars->term.is_local = 0;
	}
}
