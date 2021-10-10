/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stralnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:55:37 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 12:01:22 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../../libft/incs/libft.h"

char	*str_invalid_var_char(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
