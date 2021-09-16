/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:25:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/14 11:31:09 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

void	set_home(char *name, char *value)
{
 	if (streq(name, "HOME"))
	{
		g_minishell_data.home.value = ft_strdup(value);
		g_minishell_data.home.name = ft_strdup("HOME");
		g_minishell_data.home.is_local = 0;
	}
}
