/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvar_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:52:00 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/07 08:52:00 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"

char	*envvar_to_str(t_env_variable *envvar)
{
	char	*rvalue;
	char	*tmp;

	tmp = ft_strjoin(envvar->name, "=");
	rvalue = ft_strjoin(tmp, envvar->value);
	free(tmp);
	return (rvalue);
}
