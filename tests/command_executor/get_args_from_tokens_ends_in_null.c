/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:37:15 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main()
{
	t_token_reader	tr;
	t_token_reader	exp;
	char			**args;
	t_env_var_list	env_vars;

	env_vars = init_env_var_list();
	tr = read_tokens("cat hola");
	exp = expand_tokens(&env_vars, &tr);
	args = get_args_from_tokens(&exp, 0);
	if (!streq(args[2], NULL))
		return (-1);
	return (0);
}
