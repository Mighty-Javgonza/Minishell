/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:13:00 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 17:21:46 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include "../utils/utils.h"
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"

static char	*find_var_end(char *var_start)
{
	char	*var_end;

	var_end = str_unsc_set(var_start, " 	$'\""TOKEN_SPECIAL_CHARS);
	if (var_end == NULL)
		return (var_start + ft_strlen(var_start) - 1);
	return (var_end - 1);
}

static char	*substitute_var_in_string(char *string, char *var_start)
{
	char			*var_end;
	t_env_variable	*env_var;
	char			*new_val;
	char			*var_name;

	var_end = find_var_end(var_start + 1);
	var_name = str_in_ptrs(var_start + 1, var_end);
	env_var = find_env_var(var_name);
	free(var_name);
	if (env_var != NULL)
		new_val = subst_substr(string, var_start, var_end, env_var->value);
	else
		new_val = subst_substr(string, var_start, var_end, "");
	return (new_val);
}

static char	*find_first_var(char *search_start)
{
	while (search_start != NULL && *search_start != '$')
	{
		search_start = str_unsc_set(search_start, "$'\"");
		if (search_start != NULL && *search_start == '\'')
			search_start = str_unsc_set(search_start + 1, "'");
		else if (search_start != NULL && *search_start == '\"')
			search_start = str_unsc_set(search_start + 1, "$\"");
	}
	return (search_start);
}

void	expand_variables(t_token *token)
{
	char			*new_val;
	char			*var_start;
	
	while (1)
	{
		var_start = find_first_var(token->value);
		if (var_start == NULL)
			return ;
		new_val = substitute_var_in_string(token->value, var_start);
		free(token->value);
		token->value = new_val;
	}
}
