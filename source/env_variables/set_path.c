/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:25:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:31:25 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

void	set_path(t_env_var_list *env_vars, char *name, char *value)
{
	if (streq(name, "PATH"))
	{
		env_vars->path.name = ft_strdup("PATH");
		env_vars->path.value = ft_strdup(value);
	}
}
