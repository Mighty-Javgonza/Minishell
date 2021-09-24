/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:16:11 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:23 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

void	builtin_export(char **vars_to_export)
{
	size_t			i;
	char			**split;

	i = 1;
	while (vars_to_export[i] != NULL)
	{
		load_env_variable(vars_to_export[i]);
		split = ft_split(vars_to_export[i], '=');
		export_var(split[0]);
		ft_freearray(split);
		i++;
	}
}
