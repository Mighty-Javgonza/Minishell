/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executor.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 04:19:14 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_EXECUTOR_H
# define COMMAND_EXECUTOR_H

# define MINISHELL_PROMPT "minishell dice:"

#include "../command_interpreter/command_interpreter.h"

typedef struct s_command
{
	t_token_reader	tr;
	int				redirect_type;
	char			*out_name;
	char			*in_name;
	int				input_fd;
	int				output_fd;
	int				gets_executed;
}				t_command;

typedef struct s_sentence
{
	t_command	*commands;
	size_t		command_count;
}				t_sentence;

int	execute_command_string_form(char *command, char **args);
int	execute_command_from_path(char *command_path, char **args, char **env);
int	try_to_execute_command_on_folder(char *path, char *command, char **args, char **env);
char	**get_args_from_tokens(t_token_reader *tr, size_t start);
t_command	init_command();
void	get_command_from_tokens(t_command *command);
int	execute_command(t_command *command);
t_token_reader	get_tokens_of_command(t_token_reader *exp, size_t start_token);
t_sentence	init_sentence();
t_sentence	parse_sentence(t_token_reader *tr);
void	open_pipes(t_sentence *sentence);
int	execute_sentence(t_sentence *sentence);


void	parse_commands_of_sentence(t_sentence *sentence, t_token_reader *tr);

void	execute(char *command);

void	set_redirect_type(t_command *command);

void	set_redirect_names(t_command *command);
#endif
