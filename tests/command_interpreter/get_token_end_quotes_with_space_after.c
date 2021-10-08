/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/01 11:57:19 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	//t_token_reader	tr;

//	tr = read_tokens("\"echo\" hola");
	char	*end;

	end	 = get_token_end("\"echo\" hola");
	if (*end != '"')
		return (-1);
	return (0);
}
