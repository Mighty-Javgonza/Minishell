/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:23:42 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:34 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

//str_must be malloced

void	delete_char(char **str, char *delete)
{
	char	*old_str;

	old_str = *str;
	*str = delete_substr(*str, delete, delete);
}
