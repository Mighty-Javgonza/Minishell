/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:25:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:48:15 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

void	set_term_program(char *name, char *value)
{
	if (streq(name, "TERM_PROGRAM"))
	{
		g_minishell_data.term_program.value = ft_strdup(value);
		g_minishell_data.term_program.name = ft_strdup("TERM_PROGRAM");
	}
}
