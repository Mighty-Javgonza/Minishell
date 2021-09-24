/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:06:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 05:01:22 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/all_headers.h"
#include <readline/readline.h>

int	main(int argc, char **argv, char **env)
{
	char			*string;

	(void)argc;
	(void)argv;
	init_minishell_data();
	copy_env_variables(env);
	while (1)
	{
		string = readline("🐙->");
		execute(string);
	}
}
