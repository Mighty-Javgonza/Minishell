/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:16:11 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:21:13 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

static void	print_export_var(t_env_variable *var)
{
	printf("export %s='%s'\n", var->name, var->value);
}

static void	print_export(void)
{
	size_t			i;
	t_env_variable	*var;

	var = (t_env_variable *)&g_minishell_data;
	i = 0;
	while (i < g_minishell_data.default_env_var_count)
	{
		if (var[i].is_local == 0)
			print_export_var(&var[i]);
		i++;
	}
	var = g_minishell_data.extra_variables;
	i = 0;
	while (i < g_minishell_data.extra_variables_size)
	{
		if (var[i].is_local == 0)
			print_export_var(&var[i]);
		i++;
	}
}

void	builtin_export(char **vars_to_export)
{
	size_t			i;
	char			**split;

	i = 1;
	if (vars_to_export[i] == NULL)
	{
		print_export();
		return ;
	}
	while (vars_to_export[i] != NULL)
	{
		load_env_variable(vars_to_export[i]);
		split = ft_split(vars_to_export[i], '=');
		export_var(split[0]);
		ft_freearray(split);
		i++;
	}
}
