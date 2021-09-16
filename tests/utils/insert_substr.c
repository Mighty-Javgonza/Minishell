/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:40:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 11:35:58 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	char	*base;
	char	*start;
	char	*insert;
	char	*result;

	base = "HOLA";
	start = base + 1;
	insert = "mid";
	result = insert_substr(base, start, insert);
	if (!streq(result, "HmidOLA"))
		return (-1);
	start = base;
	result = insert_substr(base, start, insert);
	if (!streq(result, "midHOLA"))
		return (-1);
	start = base + 4;
	result = insert_substr(base, start, insert);
	if (!streq(result, "HOLAmid"))
		return (-1);
	return (0);
}
