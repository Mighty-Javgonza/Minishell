/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/10 10:11:31 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	t_token	token;

	token = get_first_token_from_string(" cat");
	if (!streq(token.value, "cat"))
		return (-1);
	return (0);
}
