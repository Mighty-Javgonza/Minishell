/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:47:01 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 10:32:16 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include <stdlib.h>
#include "../utils/utils.h"
#include "../../libft/incs/libft.h"

static char	*find_normal_case(char *token_start)
{
	char	*token_end;

	token_end = str_unsc_set((char *)token_start, " 	"TOKEN_SPECIAL_CHARS);
	if (token_end == NULL)
		return (token_start + ft_strlen(token_start));
	return (token_end - 1);
}

static char	*find_simple_quote(char *token_start)
{
	char	*token_end;

	token_start++;
	token_end = str_unsc_set(token_start, "\'");
	return (token_end);
}

static char	*find_double_quote(char *token_start)
{
	char	*token_end;

	token_start++;
	token_end = str_unsc_set(token_start, "\"");
	return (token_end);
}

static char	*find_special_case(char *token_start)
{
	char	*token_end;

	token_end = token_start;
	if (is_charset(*(token_end + 1), TOKEN_SPECIAL_CHARS))
		token_end++;
	if (is_charset(*(token_end + 1), TOKEN_SPECIAL_CHARS))
		return (NULL);
	return (token_end);
}

char	*get_token_end(t_token *token, char *token_start)
{
	char	*token_end;
	
	token_end = NULL;
	if (token->type == TOKEN_TYPE_NORMAL)
		token_end = find_normal_case(token_start);
	else if (token->type == TOKEN_TYPE_SIMPLE_QUOTE)
		token_end = find_simple_quote(token_start);
	else if (token->type == TOKEN_TYPE_DOUBLE_QUOTE)
		token_end = find_double_quote(token_start);
	else if (token->type == TOKEN_TYPE_SPECIAL)
		token_end = find_special_case(token_start);
	return (token_end);
}
