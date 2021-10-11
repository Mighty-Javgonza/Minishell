/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:53:22 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main()
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_command		command;

	tr = read_tokens("echo hola < cat > hola");
	exp = expand_tokens(NULL, &tr);
	command = init_command();
	command.tr = get_tokens_of_command(&exp, 0);
	set_redirect_type(&command);
	set_redirect_names(&command);
	if (!streq(command.in_name, "cat") || !streq(command.out_name, "hola"))
		return (-1);
	return (0);
}
