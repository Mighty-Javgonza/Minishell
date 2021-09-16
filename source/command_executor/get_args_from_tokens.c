/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_from_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:06:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/14 13:20:48 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"

char	**get_args_from_tokens(t_token_reader *tr, size_t start)
{
	size_t	i;
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
}
