/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:29:43 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 11:34:58 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../../libft/incs/libft.h"

char	*insert_substr(char *base, char *start, char *insert)
{
	char	*new_str;
	size_t	before_length;
	size_t	insert_length;
	size_t	after_length;
	size_t	total_length;

	before_length = start - base;
	after_length = ft_strlen(start);
	insert_length = ft_strlen(insert);
	total_length = before_length + insert_length + after_length;
	new_str = malloc(sizeof(*new_str) * (total_length + 1));
	ft_memmove(new_str, base, before_length);
	ft_memmove(new_str + before_length, insert, insert_length);
	ft_memmove(new_str + before_length + insert_length, start, after_length);
	new_str[total_length] = '\0';
	return (new_str);
}
