/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:06:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/26 12:42:23 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/all_headers.h"
#include <signal.h>
#include <readline/readline.h>

pid_t	loop_pid;

void	ctrl_c(int a)
{
	(void)a;
	kill(loop_pid, SIGINT);
	printf("\n");
}

void	ctrl_d(int a)
{
	(void)a;
	printf("KILL\n");
	exit(0);
}

void	wait_loop()
{
	char	*string;

	while (1)
	{
		string = readline("🐙->");
		add_history(string);
		execute(string);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, ctrl_c);
	signal(SIGKILL, ctrl_d);
	init_minishell_data();
	copy_env_variables(env);
	while (1)
	{
		loop_pid = fork();
		if (loop_pid == 0)
			wait_loop();
		else
			waitpid(loop_pid, NULL, 0);
	}
}
