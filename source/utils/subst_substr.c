/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subst_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:38:08 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:07:39 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

char	*subst_substr(char *base, char *start, char *end, char *insert)
{
	char	*delete;
	char	*subst;

	delete = delete_substr(base, start, end);
	subst = insert_substr(delete, start - base + delete, insert);
	free(delete);
	return (subst);
}
