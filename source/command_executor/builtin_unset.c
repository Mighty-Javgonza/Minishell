/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:18:56 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:15 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"

void	builtin_unset(char **args)
{
	t_env_variable	*var;

	args++;
	while (*args != NULL)
	{
		var = find_env_var(*args);
		if (var != NULL)
		{
			var->is_local = 1;
			if (var->value != NULL)
				free(var->value);
			var->value = ft_strdup("");
		}
		args++;
	}
}
