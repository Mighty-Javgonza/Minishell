/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token_reader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:21:12 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:31 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"

t_token_reader	init_token_reader(void)
{
	t_token_reader	rvalue;

	rvalue = (t_token_reader)
	{
		.tokens = NULL,
		.token_count = 0,
	};
	return (rvalue);
}
