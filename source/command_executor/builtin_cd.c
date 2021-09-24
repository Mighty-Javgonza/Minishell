/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:14:04 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:22 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <unistd.h>
#include <stdlib.h>
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

void	builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		chdir(g_minishell_data.home.value);
		set_variable("PWD", g_minishell_data.home.value);
	}
	else
	{
		chdir(args[1]);
		set_variable("PWD", args[1]);
	}
}
