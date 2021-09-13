/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 10:31:18 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	t_token	token;
	char	*string;

	string = ft_strdup("\\|");
	token = get_first_token_from_string(string);
 printf("%s\n", string);
 printf("%s\n", token.value);
 printf("%d\n", token.type);
	if (!streq(token.value, string))
		return (-1);
	return (0);
}
