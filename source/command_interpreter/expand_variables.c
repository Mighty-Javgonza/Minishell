/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:13:00 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:25:48 by javgonza         ###   ########.fr       */
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

static int	check_dollar_can_be_printed(char *var_name, char *var_start,
			int is_inside_dquote)
{
	int	can_be_printed;

	can_be_printed = (ft_isalnum(var_name[0]) == '\0');
	can_be_printed &= ft_isalnum(var_start[1]) == 0;
	can_be_printed &= !(is_charset(var_start[1], "\"'")
			&& !is_inside_dquote && var_start[1] != '\0');
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
			size_t *read_chars, int is_inside_dquote)
{
	char			*var_end;
	t_env_variable	*env_var;
	char			*new_val;
	char			*var_name;

	var_end = find_var_end(var_start + 1);
	var_name = str_in_ptrs(var_start + 1, var_end);
	if (check_dollar_can_be_printed(var_name, var_start, is_inside_dquote) == 1)
	{
		free(var_name);
		return (print_dollar(string, read_chars));
	}
	env_var = find_env_var(var_name);
	free(var_name);
	if (env_var != NULL)
	{
		new_val = subst_substr(string, var_start, var_end, env_var->value);
		(*read_chars) += ft_strlen(env_var->value);
	}
	else
	{
		new_val = subst_substr(string, var_start, var_end, "");
		(*read_chars) += 0;
	}
	return (new_val);
}

void	expand_variables(t_token *token)
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
		else
			new_val = substitute_var_in_string(token->value, var_start,
					&read_chars, inside_dquote);
		free(token->value);
		token->value = new_val;
		token->type |= TOKEN_TYPE_VARIABLE;
	}
}
