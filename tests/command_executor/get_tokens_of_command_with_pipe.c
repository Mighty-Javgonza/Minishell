/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/28 11:24:02 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main()
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_command		command;

	tr = init_token_reader();
	tr = read_tokens("cat hola amigo | si");
	exp = expand_tokens(&tr);
	command = init_command();
	command.tr = get_tokens_of_command(&exp, 0);
 printf("%zu\n", command.tr.token_count);
	if (command.tr.token_count != 4)
		return (-1);
	return (0);
}
