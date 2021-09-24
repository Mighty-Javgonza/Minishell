/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:06:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 07:49:26 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/all_headers.h"
#include <signal.h>
#include <readline/readline.h>

void	ctrl_c(int a)
{
	(void)a;
 printf("\nOK to here!\n");
}

void	ctrl_d(int a)
{
	(void)a;
 printf("KILL\n");
 exit(0);
}

int	main(int argc, char **argv, char **env)
{
	char			*string;

	(void)argc;
	(void)argv;
	signal(SIGINT, ctrl_c);
	signal(SIGKILL, ctrl_d);
	init_minishell_data();
	copy_env_variables(env);
	while (1)
	{
		string = readline("🐙->");
		add_history(string);
		execute(string);
	}
}
