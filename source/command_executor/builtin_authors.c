/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_authors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:15:09 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 07:44:33 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include <unistd.h>
#include <stdlib.h>
#include "../env_variables/env_variables.h"
#include "../utils/utils.h"

void	builtin_authors(char **args)
{
	char	*jav_path;
	char	*baz_path;
	char	*auth_args[3];

	(void)args;
	jav_path = PROJECT_DIR"/authors/facegonza.term";
	baz_path = PROJECT_DIR"/authors/facezuara.term";
	auth_args[0] = "cat";
	auth_args[1] = baz_path;
	auth_args[2] = NULL;
	execute_command_string_form(auth_args[0], auth_args);
	auth_args[1] = jav_path;
	execute_command_string_form(auth_args[0], auth_args);
}
