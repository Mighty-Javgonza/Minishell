/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:47:01 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 09:46:11 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include <stdlib.h>
#include "../utils/utils.h"
#include "../../libft/incs/libft.h"

static void	move_pointer_to_end_of_special_chars(char **token_end)
{
	char	tt;

	if (is_charset(**token_end, TOKEN_SPECIAL_CHARS))
	{
		tt = *(*token_end + 1);
		if (is_charset(tt, TOKEN_SPECIAL_CHARS))
		{
			if (*(*token_end + 2) != '\0' && is_charset(*(*token_end + 2),
					TOKEN_SPECIAL_CHARS))
				(*token_end) = NULL;
			else
				(*token_end)++;
		}
	}
}

static int	move_pointer_to_token_end(char **token_end, char *loop_start)
{
	int	end_found;

	end_found = 0;
	if (*token_end == NULL)
	{
		end_found = 1;
		*token_end = loop_start + ft_strlen(loop_start) - 1;
	}
	else if (**token_end == '"')
		*token_end = str_unsc_set(*token_end + 1, "\"");
	else if (**token_end == '\'')
		*token_end = str_unsc_set(*token_end + 1, "\'");
	else if (loop_start == *token_end)
	{
		end_found = 1;
		move_pointer_to_end_of_special_chars(token_end);
	}
	else
	{
		end_found = 1;
		(*token_end)--;
	}
	return (end_found);
}

char	*get_token_end(char *token_start)
{
	char	*token_end;
	int		end_found;
	char	*loop_start;

	end_found = 0;
	token_end = NULL;
	token_start = strcharset_n(token_start, " \t");
	if (token_start == NULL)
		return (NULL);
	loop_start = token_start;
	while (end_found != 1)
	{
		token_end = str_unsc_set(loop_start, " \t\"'"TOKEN_SPECIAL_CHARS);
		end_found = move_pointer_to_token_end(&token_end, loop_start);
		loop_start = token_end + 1;
		if (loop_start == (char *)1 || *loop_start == ' ')
			break ;
		if (token_end == NULL)
			break ;
	}
	return (token_end);
}
