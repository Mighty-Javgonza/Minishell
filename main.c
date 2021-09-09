/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:14:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/09 13:54:24 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/all_headers.h"
#include <stdio.h>
#include <readline/readline.h>

static void	read_command()
{
	char	*command;
	char	*command_args[2];

	command = readline("🐙 ->");
	if (command == NULL)
	{
		printf("\n");
		exit(0);
	}
	command_args[0] = command;
	command_args[1] = NULL;
	execute_command(command, command_args);
}

static void	ctrl_c()
{
	printf("\n");
	read_command();
}

static void	ctrl_d()
{
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	printf("Bienvenido al minishell\n");
	init_minishell_data();
	copy_env_variables(env);
	signal(SIGINT, ctrl_c);
	signal(SIGKILL, ctrl_d);
	while (1)
	{
		read_command();
	}
	return (0);
}
