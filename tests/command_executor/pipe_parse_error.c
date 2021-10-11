/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 11:52:48 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int	main(int argc, char **argv, char **env)
{
	t_sentence		sentence;
	t_token_reader	tr;
	t_token_reader	exp;

	(void)argv;
	(void)argc;
	(void)env;
	tr = read_tokens("|");
	exp = expand_tokens(NULL, &tr);
	sentence = parse_sentence(&exp);
	if (sentence.command_count != 0)
		return (-1);
	return (0);
}
