/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sentence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:09:14 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/30 14:17:32 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"

void	destroy_sentence(t_sentence *sentence)
{
	size_t	i;

	i = 0;
	while (i < sentence->command_count)
	{
		destroy_command(&sentence->commands[i]);
		i++;
	}
	free(sentence->commands);
}
