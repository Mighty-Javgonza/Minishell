/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_from_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:06:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/28 10:13:02 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"

static int	token_is_non_ending(t_token *token)
{
	return (token->type == TOKEN_TYPE_REDIRECT_INPUT
		|| token->type == TOKEN_TYPE_REDIRECT_OUTPUT
		|| token->type == TOKEN_TYPE_REDIRECT_OUTPUT_APPEND
		|| token->type == TOKEN_TYPE_REDIRECT_INPUT_DELIMITER);
}

static char	**get_args_char(char **too_big_args, size_t arg_count)
{
	char	**args;
	size_t	i;

	args = malloc(sizeof(*args) * (arg_count + 1));
	args[arg_count] = NULL;
	i = 0;
	while (i < arg_count)
	{
		args[i] = ft_strdup(too_big_args[i]);
		i++;
	}
	return (args);
}

char	**get_args_from_tokens(t_token_reader *tr, size_t start)
{
	char	**too_big_args;
	size_t	i;
	size_t	arg_count;
	t_token	*token;
	char	**args;

	too_big_args = malloc(sizeof(*too_big_args) * tr->token_count);
	arg_count = 0;
	i = start;
	while (i < tr->token_count && tr->tokens[i].type != TOKEN_TYPE_PIPE)
	{
		token = &tr->tokens[i];
		if (token_is_non_ending(token))
			i++;
		else
		{
			too_big_args[arg_count] = token->value;
			arg_count++;
		}
		i++;
	}
	args = get_args_char(too_big_args, arg_count);
	free(too_big_args);
	return (args);
}
