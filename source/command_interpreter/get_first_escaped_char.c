/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_escaped_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:46:12 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 11:47:29 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"

char	*get_first_escaped_char(char *string)
{
	char	*escaped;

	escaped = malloc(sizeof(*escaped) * 2);
	escaped[0] = string[1];
	escaped[1] = '\0';
	return (escaped);
}
