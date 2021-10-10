/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_charset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:19:40 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:35 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../../libft/incs/libft.h"

int	is_charset(char c, char *set)
{
	char	*place_in_set;

	place_in_set = ft_strchr(set, c);
	return (place_in_set != NULL);
}
