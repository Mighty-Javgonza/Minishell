/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 12:05:03 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int	main()
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_token_reader	command_tokens;

	tr = read_tokens("echo | |");
	exp = expand_tokens(NULL, &tr);
	command_tokens = get_tokens_of_command(&exp, 2);
	if (command_tokens.token_count != 0)
		return (-1);
	return (0);
}
