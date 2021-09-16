/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 13:51:01 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	t_token			token;
	t_token_reader	tr;

	tr = init_token_reader();
	token = init_token();
	token.value = "\\ho\\la";
	token.type = TOKEN_TYPE_NORMAL;
	add_expansion_to_reader(&tr, &token);
	if (!streq(tr.tokens[0].value, "hola"))
		return (-1);
	return (0);
}
