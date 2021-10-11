/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:25:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:34:00 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

void	set_term_program(t_env_var_list *env_vars, char *name, char *value)
{
	if (streq(name, "TERM_PROGRAM"))
	{
		env_vars->term_program.value = ft_strdup(value);
		env_vars->term_program.name = ft_strdup("TERM_PROGRAM");
	}
}
