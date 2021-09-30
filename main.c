/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:06:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/27 11:13:04 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/all_headers.h"
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "/Users/javgonza/.brew/opt/readline/include/readline/readline.h"

void	ctrl_c(int a)
{
	(void)a;
	write(0, "\n", 1);
	g_minishell_data.cancelling_command = 1;
	if (!g_minishell_data.executing_command)
	{
		rl_on_new_line();
		rl_line_buffer[0] = '\0';
		rl_point = 0;
		rl_end = 0;
		rl_redisplay();
	}
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
		if (string == NULL)
		{
			exit(0);
		}
		add_history(string);
		g_minishell_data.executing_command = 1;
		execute(string);
		g_minishell_data.executing_command = 0;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, ctrl_c);
//	signal(SIGKILL, ctrl_d);
	init_minishell_data();
	copy_env_variables(env);
	wait_loop();
}
