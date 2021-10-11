/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:18:02 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 13:27:48 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

void	init_minishell_data(void)
{
	g_minishell_data.error_code = 0;
	g_minishell_data.command_exists = 0;
}
