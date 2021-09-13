/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:14:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/13 10:37:41 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/all_headers.h"
#include <stdio.h>
#include <readline/readline.h>

static void	read_command()
{
	size_t	i;
	char			*command;
	t_token_reader	tr;
	char			**args;

	command = readline("🐙 ->");
	add_history(command);
	tr = read_tokens(command);
	args = malloc(sizeof(*args) * (tr.token_count + 1));
	i = 0;
	while (i < tr.token_count)
	{
		args[i] = tr.tokens[i].value;
		i++;
	}
	args[i] = NULL;
	if (command == NULL)
	{
		printf("\n");
		exit(0);
	}
	execute_command(args[0], args);
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
