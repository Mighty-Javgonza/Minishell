/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:17:07 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:13 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

void	builtin_echo(char **args)
{
	int				writes_nl;

	writes_nl = 1;
	args++;
	if (streq(args[0], "-n"))
	{
		writes_nl = 0;
		args++;
	}
	while (*args != NULL)
	{
		ft_putstr_fd(*args, STDOUT_FILENO);
		args++;
		if (*args != NULL)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (writes_nl)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
