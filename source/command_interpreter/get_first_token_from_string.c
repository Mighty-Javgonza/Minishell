/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_token_from_string.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:05:36 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/14 09:30:20 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include "../../libft/incs/libft.h"
#include "../utils/utils.h"

static char	*get_token_start(char *string)
{
	char	*token_start;
	
	token_start = strcharset_n(string, " 	");
	return (token_start);
}

t_token	get_first_token_from_string(char *string)
{
	t_token	token;
	char	*token_start;
	char	*token_end;

	token = init_token();
	token_start = get_token_start(string);
	if (token_start == NULL)
		return (token);
	token_end = get_token_end(token_start);
	if (token_end == NULL)
		return (token);
	token.value = str_in_ptrs(token_start, token_end);
	token.end = token_end;
	return (token);
}
