/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 17:02:43 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	t_token			token;

	init_minishell_data();
	load_env_variable("VAR=hola");
	token = init_token();
	token.value = ft_strdup("a'$VAR'");
	expand_variables(&token);
	if (!streq(token.value, "a'$VAR'"))
		return (-1);
	return (0);
}
