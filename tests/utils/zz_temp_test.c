/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:40:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 12:11:53 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	char	*a;
	char	*b;

	a = "";
	b = "Hola";
	if (streq(a, b) != 0)
		return (-1);
	a = "Hola";
	b = "";
	if (streq(a, b) != 0)
		return (-1);
	a = "Hola";
	b = "Hola";
	if (streq(a, b) != 1)
		return (-1);
	return (0);
}
