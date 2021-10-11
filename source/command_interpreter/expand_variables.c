/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:13:00 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 18:01:36 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include "../utils/utils.h"
#include "../../libft/incs/libft.h"
#include "../env_variables/env_variables.h"

static char	*find_var_end(char *var_start)
{
	char	*var_end;

	var_end = str_invalid_var_char(var_start);
	if (var_end == NULL)
		return (var_start + ft_strlen(var_start) - 1);
	return (var_end - 1);
}

static int	check_dollar_can_be_printed(char *var_start,
			int is_inside_dquote)
{
	int		can_be_printed;
	char	*var_end;
	char	*var_name;

	var_end = find_var_end(var_start + 1);
	var_name = str_in_ptrs(var_start + 1, var_end);
	can_be_printed = (ft_isalnum(var_name[0]) == 0 && var_name[0] != '_');
	can_be_printed &= ft_isalnum(var_start[1]) == 0;
	can_be_printed &= !(is_charset(var_start[1], "\"'")
			&& !is_inside_dquote && var_start[1] != '\0');
	free(var_name);
	return (can_be_printed);
}

static char	*print_dollar(char *string, size_t *read_chars)
{
	char	*new_val;

	new_val = ft_strdup(string);
	(*read_chars)++;
	return (new_val);
}

static char	*substitute_var_in_string(char *string, char *var_start,
			size_t *read_chars, t_env_var_list *env_vars)
{
	char			*var_end;
	t_env_variable	*env_var;
	char			*new_val;
	char			*var_name;

	var_end = find_var_end(var_start + 1);
	var_name = str_in_ptrs(var_start + 1, var_end);
	env_var = find_env_var(env_vars, var_name);
	free(var_name);
	if (env_var != NULL)
	{
		new_val = subst_substr(string, var_start, var_end, env_var->value);
		(*read_chars) += ft_strlen(env_var->value);
	}
	else
		new_val = subst_substr(string, var_start, var_end, "");
	return (new_val);
}

void	expand_variables(t_env_var_list *env_vars, t_token *token)
{
	char			*new_val;
	char			*var_start;
	size_t			read_chars;
	int				inside_dquote;

	read_chars = 0;
	inside_dquote = 0;
	while (1)
	{
		var_start = find_first_var(token->value + read_chars, &inside_dquote);
		if (var_start == NULL)
			return ;
		if (*(var_start + 1) == '?')
			new_val = expand_error_var(token->value, var_start);
		else if (check_dollar_can_be_printed(var_start, inside_dquote) == 1)
			new_val = print_dollar(token->value, &read_chars);
		else
			new_val = substitute_var_in_string(token->value, var_start,
					&read_chars, env_vars);
		free(token->value);
		token->value = new_val;
		token->type |= TOKEN_TYPE_VARIABLE;
	}
}
