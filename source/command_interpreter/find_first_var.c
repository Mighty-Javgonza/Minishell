/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:10:57 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/05 11:11:40 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include "../utils/utils.h"

static void	switch_is_inside_dquote(char *search_start, int *is_inside_dquote)
{
	if (search_start != NULL && *search_start == '"')
		(*is_inside_dquote) = !(*is_inside_dquote);
}

static char *advance_search_start(char *search_start, int *is_inside_dquote)
{
	search_start = str_unsc_set(search_start, "$'\"");
	switch_is_inside_dquote(search_start, is_inside_dquote);
	if (search_start != NULL && *search_start == '\'')
	{
		if (*is_inside_dquote)
			search_start++;
		else
			search_start = str_unsc_set(search_start + 1, "'");
	}
	else if (search_start != NULL && *search_start == '\"')
	{
		search_start = str_unsc_set(search_start + 1, "$\"");
		switch_is_inside_dquote(search_start, is_inside_dquote);
	}
	return (search_start);
}

char	*find_first_var(char *search_start, int *is_inside_dquote)
{
	while (search_start != NULL && *search_start != '$')
		search_start = advance_search_start(search_start, is_inside_dquote);
	return (search_start);
}
