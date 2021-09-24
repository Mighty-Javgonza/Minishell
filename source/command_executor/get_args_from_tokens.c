/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_from_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:06:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 05:20:46 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"

char	**get_args_from_tokens(t_token_reader *tr, size_t start)
{
/*	size_t	i;
	char	**args;
	size_t	final_token;
	size_t	args_size;

	final_token = start;
	while (final_token < tr->token_count && tr->tokens[final_token].type == TOKEN_TYPE_NORMAL)
		final_token++;
	args_size = final_token - start;
	args = malloc(sizeof(*args) * (args_size + 1));
	i = 0;
	while (i < args_size)
	{
		args[i] = ft_strdup(tr->tokens[i + start].value);
		i++;
	}
	args[i + start] = NULL;
	return (args);
*/
	char	*too_big_args[tr->token_count];
	size_t	i;
	size_t	arg_count;
	t_token	*token;
	char	**args;

	arg_count = 0;
	i = start;
	while (i < tr->token_count && tr->tokens[i].type != TOKEN_TYPE_PIPE)
	{
		token = &tr->tokens[i];
		if (token->type == TOKEN_TYPE_REDIRECT_INPUT || token->type == TOKEN_TYPE_REDIRECT_OUTPUT)
			i++;
		else
		{
			too_big_args[arg_count] = token->value;
			arg_count++;
		}
		i++;
	}
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
