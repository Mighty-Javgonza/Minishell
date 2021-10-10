/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:16:59 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:35 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../../libft/incs/libft.h"

char	*delete_substr(char *base, char *start, char *end)
{
	char	*new_str;
	size_t	before_length;
	size_t	after_length;

	before_length = start - base;
	after_length = ft_strlen(end) - 1;
	new_str = malloc(sizeof(*new_str) * (before_length + after_length + 1));
	ft_memmove(new_str, base, before_length);
	ft_memmove(new_str + before_length, end + 1, after_length);
	new_str[before_length + after_length] = '\0';
	return (new_str);
}
