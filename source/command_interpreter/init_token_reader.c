/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token_reader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:21:12 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/10 12:21:15 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"

t_token_reader	init_token_reader()
{
	t_token_reader	rvalue;

	rvalue = (t_token_reader)
	{
		.tokens = NULL,
		.token_count = 0,
	};
	return (rvalue);
}
