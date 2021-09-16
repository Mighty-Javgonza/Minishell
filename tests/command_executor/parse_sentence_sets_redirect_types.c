/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/15 13:17:00 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include <readline/readline.h>

int main()
{
	t_token_reader	tr;
	t_token_reader	exp;
	t_sentence		sentence;

	tr = init_token_reader();
	tr = read_tokens("cat hola amigo | si turut | wc");
	exp = expand_tokens(&tr);
	sentence = parse_sentence(&exp);
	open_pipes(&sentence);
	if (sentence.commands[0].redirect_type != TOKEN_TYPE_PIPE)
		return (-1);
	return (0);
}
