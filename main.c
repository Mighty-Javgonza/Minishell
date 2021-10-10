/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:06:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 12:02:32 by javgonza         ###   ########.fr       */
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
	write(1, "\33[2K", 4);
	write(1, "🐙->", 6);
	write(1, rl_line_buffer, rl_end);
	write(0, "\n", 1);
	g_minishell_data.cancelling_command = 1;
	g_minishell_data.error_code = 130;
	if (!g_minishell_data.executing_command)
	{
		rl_on_new_line();
		rl_line_buffer[0] = '\0';
		rl_point = 0;
		rl_end = 0;
		rl_redisplay();
	}
}

void	ctrl_bar(int a)
{
	(void)a;
	if (!g_minishell_data.executing_command)
	{
		write(1, "\33[2K", 4);
		write(1, "🐙->", 6);
		write(1, rl_line_buffer, rl_end);
	}
	else
	{
		write(1, "sig quit", 8);
		write(1, "\n", 1);
	}
}

void	wait_loop(void)
{
	char	*string;

	while (1)
	{
		string = readline("🐙->");
		if (string == NULL)
			exit(0);
		add_history(string);
		g_minishell_data.executing_command = 1;
		execute(string);
		g_minishell_data.executing_command = 0;
		free(string);
	}
}

int	main(int argc, char **argv, char **env)
{
	struct sigaction	action;

	action.sa_handler = &ctrl_c;
	(void)argc;
	(void)argv;
	sigaction(SIGINT, &action, NULL);
	signal(SIGQUIT, ctrl_bar);
	init_minishell_data();
	copy_env_variables(env);
	increment_shell_level();
	wait_loop();
}
