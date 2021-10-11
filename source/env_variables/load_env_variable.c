/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_env_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:21:55 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:19:37 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../utils/utils.h"
#include "../command_executor/command_executor.h"

//TODO: Hacer todas las variables default

static void	set_def_var(t_env_var_list *env_vars, char **split)
{
	set_term_program(env_vars, split[0], split[1]);
	set_term(env_vars, split[0], split[1]);
	set_shell(env_vars, split[0], split[1]);
	set_path(env_vars, split[0], split[1]);
	set_home(env_vars, split[0], split[1]);
	set_pwd(env_vars, split[0], split[1]);
}

static void	set_split_to_empty_var(char ***split)
{
	char	*var_name;

	var_name = ft_strdup((*split)[0]);
	ft_freearray(*split);
	*split = malloc(sizeof(*split) * 3);
	(*split)[0] = var_name;
	(*split)[1] = ft_strdup("");
	(*split)[2] = NULL;
}

static void	load_as_extra_variable(t_env_var_list *env_vars, char **split,
			char *var)
{
	t_env_variable	*existing_var;

	existing_var = find_extra_var(env_vars, split[0]);
	if (existing_var == NULL)
		load_extra_variable(env_vars, var);
	else
		set_variable(env_vars, split[0], split[1]);
}

void	load_env_variable(t_env_var_list *env_vars, char *var)
{
	char			**split;
	t_env_variable	*existing_var;

	if (var == NULL || *var == '\0')
		return ;
	if (ft_isdigit(var[0]) || str_invalid_var_char(var) != NULL)
	{
		printf(MINISHELL_PROMPT"no es un identificador válido\n");
		return ;
	}
	split = ft_split(var, '=');
	if (split[1] == NULL)
		set_split_to_empty_var(&split);
	set_def_var(env_vars, split);
	existing_var = find_default_var(env_vars, split[0]);
	if (existing_var == NULL)
		load_as_extra_variable(env_vars, split, var);
	ft_freearray(split);
}
