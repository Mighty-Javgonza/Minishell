/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:40:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/10 10:24:00 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	char	*set;
	char	*found;
	char	*string;

	set = "abc";
	string = "abc";
	found = strcharset(string, set);
	if (found != set)
		return (-1);
	return (0);
}
