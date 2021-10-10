/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_token_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:11:59 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:25 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"

void	destroy_token_reader(t_token_reader *tr)
{
	size_t	i;

	i = 0;
	while (i < tr->token_count)
	{
		destroy_token(&tr->tokens[i]);
		i++;
	}
	free(tr->tokens);
}
