/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:14:50 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int	main()
{
	t_token_reader	tr;
	t_token_reader	exp;

	init_minishell_data();
	load_env_variable("my_var='|'");
	export_var("my_var");
	tr = read_tokens("$my_var");
	exp = expand_tokens(&tr);
	if (exp.tokens[0].type != TOKEN_TYPE_NORMAL)
		return (-1);
	return (0);
}
