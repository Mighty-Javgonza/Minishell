/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sentence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:37:28 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:26 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"

t_sentence	init_sentence(void)
{
	t_sentence	rvalue;

	rvalue = (t_sentence)
	{
		.commands = NULL,
		.command_count = 0,
	};
	return (rvalue);
}
