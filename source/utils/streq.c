/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:41:51 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:37 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include "../../libft/incs/libft.h"

int	streq(char *a, char *b)
{
	size_t	len_a;
	size_t	len_b;

	if (a == b)
		return (1);
	if (a == NULL || b == NULL)
		return (0);
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (len_a != len_b)
		return (0);
	return (ft_strncmp(a, b, len_a) == 0);
}
