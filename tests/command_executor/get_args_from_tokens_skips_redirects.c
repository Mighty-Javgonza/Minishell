/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 05:08:05 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	t_token_reader	tr;
	t_token_reader	exp;
	char			**args;

	tr = read_tokens("hola > pa ti");
	exp = expand_tokens(&tr);
	args = get_args_from_tokens(&exp, 0);
	if (!streq(args[1], "ti"))
		return (-1);
	return (0);
}
