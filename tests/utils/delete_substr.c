/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:40:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 16:49:47 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	char	*base;
	char	*start;
	char	*end;
	char	*result;

	base = "HOLA";
	start = base + 1;
	end = base + 2;
	result = delete_substr(base, start, end);
	if (!streq(result, "HA"))
		return (-1);
	start = base;
	end = base;
	result = delete_substr(base, start, end);
	if (!streq(result, "OLA"))
		return (-1);
	start = base + 3;
	end = base + 3;
	result = delete_substr(base, start, end);
	if (!streq(result, "HOL"))
		return (-1);
	start = base;
	end = base + 3;
	result = delete_substr(base, start, end);
	if (!streq(result, ""))
		return (-1);
	return (0);
}
