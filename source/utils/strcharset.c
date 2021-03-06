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
#include <stdlib.h>

char	*strcharset(char *string, char *set)
{
	char	*search;

	if (string == NULL)
		return (NULL);
	search = string;
	while (!is_charset(*search, set) && *search != '\0')
		search++;
	if (*search == '\0')
		return (NULL);
	return (search);
}
