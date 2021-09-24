/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:25:54 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:47:47 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"

void	set_pwd(char *name, char *value)
{
	if (streq(name, "PWD"))
	{
		g_minishell_data.pwd.value = ft_strdup(value);
		g_minishell_data.pwd.name = ft_strdup("PWD");
		g_minishell_data.pwd.is_local = 0;
	}
}
