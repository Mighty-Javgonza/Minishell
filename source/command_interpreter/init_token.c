/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:04:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/10 11:46:53 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include <stdlib.h>

t_token	init_token()
{
	t_token	rvalue;

	rvalue = (t_token)
	{
		.value = NULL,
		.type = TOKEN_TYPE_NORMAL,
		.end = NULL,
	};
	return (rvalue);
}
