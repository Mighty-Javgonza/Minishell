/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 15:56:16 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	t_token_reader	tr;
	t_token			token;

	tr = init_token_reader();
	token = init_token();
	token.value = ft_strdup("\"hola\"aa\"oo\"");
	add_expansion_to_reader(&tr, &token);
	if (!streq(tr.tokens[0].value, "holaaaoo"))
		return (-1);
	return (0);
}
