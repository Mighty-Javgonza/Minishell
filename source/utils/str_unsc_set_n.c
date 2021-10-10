/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcharset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:24:03 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:36 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

char	*str_unsc_set_n(char *string, char *set)
{
	char	*search;
	int		char_escape;

	if (string == NULL)
		return (NULL);
	search = string;
	while ((is_charset(*search, set) || char_escape) && *search != '\0')
	{
		char_escape = *search == '\\' && !char_escape;
		search++;
	}
	if (*search == '\0')
		return (NULL);
	return (search);
}
