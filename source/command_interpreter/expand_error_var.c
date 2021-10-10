/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_error_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:40:56 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:26 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_interpreter.h"
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

char	*expand_error_var(char *string, char *var_start)
{
	char	*error;
	char	*new_val;

	error = ft_itoa(g_minishell_data.error_code);
	new_val = subst_substr(string, var_start, var_start + 1, error);
	free(error);
	return (new_val);
}
