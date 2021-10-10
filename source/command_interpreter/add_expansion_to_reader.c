/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_expansion_to_reader.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:59:12 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:24 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include "../../libft/incs/libft.h"
#include "../utils/utils.h"

static void	expand_escape_chars(t_token *token)
{
	char	*escape_char;
	size_t	escape_index;

	escape_char = ft_strchr(token->value, '\\');
	while (escape_char != NULL)
	{
		escape_index = escape_char - token->value;
		delete_char(&token->value, escape_char);
		token->end = token->value + escape_index;
		escape_char = ft_strchr(token->end, '\\');
	}
}

static void	expand_quotes(t_token *token)
{
	char	*open_quote;
	char	*close_quote;
	char	type[2];
	size_t	quote_index;

	open_quote = str_unsc_set(token->value, "\"\'");
	quote_index = open_quote - token->value;
	type[1] = '\0';
	while (open_quote != NULL)
	{
		type[0] = *open_quote;
		delete_char(&token->value, open_quote);
		close_quote = str_unsc_set(token->value + quote_index, type);
		quote_index = close_quote - token->value;
		delete_char(&token->value, close_quote);
		open_quote = str_unsc_set(token->value + quote_index, "\"\'");
		quote_index = open_quote - token->value;
	}
}

void	add_expansion_to_reader(t_token_reader *tr, t_token *token)
{
	t_token	new_token;

	new_token = init_token();
	new_token.value = ft_strdup(token->value);
	new_token.type = token->type;
	expand_variables(&new_token);
	expand_quotes(&new_token);
	expand_escape_chars(&new_token);
	if (new_token.type == TOKEN_TYPE_VARIABLE)
		new_token.type = TOKEN_TYPE_NORMAL;
	else if (streq(new_token.value, "|"))
		new_token.type = TOKEN_TYPE_PIPE;
	else if (streq(new_token.value, ">>"))
		new_token.type = TOKEN_TYPE_REDIRECT_OUTPUT_APPEND;
	else if (streq(new_token.value, "<<"))
		new_token.type = TOKEN_TYPE_REDIRECT_INPUT_DELIMITER;
	else if (streq(new_token.value, ">"))
		new_token.type = TOKEN_TYPE_REDIRECT_OUTPUT;
	else if (streq(new_token.value, "<"))
		new_token.type = TOKEN_TYPE_REDIRECT_INPUT;
	else
		new_token.type = TOKEN_TYPE_NORMAL;
	add_token(tr, new_token);
}
