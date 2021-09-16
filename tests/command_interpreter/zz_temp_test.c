/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/14 13:03:00 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	t_token_reader	tr;
	t_token_reader	exp;

	tr = read_tokens("<<");
	exp = expand_tokens(&tr);
	if (exp.tokens[0].type != TOKEN_TYPE_REDIRECT_INPUT_DELIMITER)
		return (-1);
	return (0);
}
