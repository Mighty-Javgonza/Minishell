/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:40:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 11:39:58 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	char	*base;
	char	*start;
	char	*end;
	char	*insert;
	char	*result;
	
	base = "HOLA";
	start = base + 1;
	end = base + 2;
	insert = "mid";
	result = subst_substr(base, start, end, insert);
	if (!streq(result, "HmidA"))
		return (-1);
	return (0);
}
