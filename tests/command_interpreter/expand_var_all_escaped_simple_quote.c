/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 12:11:47 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int main()
{
	t_token			token;
	t_env_var_list	env_vars;

	env_vars = init_env_var_list();
	load_env_variable(&env_vars, "VAR=hola");
	token = init_token();
	token.value = ft_strdup("'$VAR'");
	expand_variables(&env_vars, &token);
	if (!streq(token.value, "'$VAR'"))
		return (-1);
	return (0);
}
