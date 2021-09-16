/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/15 09:31:37 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main()
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_command		command;
	t_command		command2;

	tr = init_token_reader();
	tr = read_tokens("cat hola amigo | si turut");
	exp = expand_tokens(&tr);
	command = init_command();
	command.tr = get_tokens_of_command(&exp, 0);
	command2 = init_command();
	command2.tr = get_tokens_of_command(&exp, command.tr.token_count + 1);
	if (!streq(command2.tr.tokens[1].value, "turut"))
		return (-1);
	return (0);
}
