/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:40:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/10 10:39:21 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	char	*string;
	char	*start;
	char	*end;
	char	*result;

	string = "Hola";
	start = string;
	end = string + 1;
	result = str_in_ptrs(start, end);
	if (!streq(result, "H"))
		return (-1);
	return (0);
}
