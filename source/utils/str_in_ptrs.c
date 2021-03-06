/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_in_ptrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:37:05 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:35 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

char	*str_in_ptrs(char *start, char *end)
{
	size_t	length;
	char	*new;

	length = end - start + 1;
	new = malloc(sizeof(*new) * (length + 1));
	ft_memmove(new, start, length);
	new[length] = '\0';
	return (new);
}
