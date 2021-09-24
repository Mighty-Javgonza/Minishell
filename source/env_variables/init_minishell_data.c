/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:18:02 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:37:59 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

void	init_minishell_data(void)
{
	ft_memset(&g_minishell_data, 0, sizeof(g_minishell_data));
	g_minishell_data.extra_variables = malloc(
			sizeof(*g_minishell_data.extra_variables));
	g_minishell_data.extra_variables->name = NULL;
	g_minishell_data.extra_variables_size = 0;
	g_minishell_data.default_env_var_count = 27;
}
