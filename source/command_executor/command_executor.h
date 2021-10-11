/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executor.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:00:28 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_EXECUTOR_H
# define COMMAND_EXECUTOR_H

# define MINISHELL_PROMPT "minishell dice:"

# include "../command_interpreter/command_interpreter.h"
# include "../env_variables/env_variables.h"

# define OUTPUT_REDIRS (0b1100)
# define INPUT_REDIRS (0b10010)

# define ERROR_COMMAND_NOT_FOUND 127
# define ERROR_NO_SUCH_FILE_OR_DIRECTORY 1
# define ERROR_IS_A_DIRECTORY 126
# define ERROR_SEGFAULT 11
# define ERROR_IN_PARSE 258

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

typedef void	(*t_builtin)(char **args, t_env_var_list *envvars);

typedef struct s_named_builtin
{
	t_builtin	builtin;
	char		name[10];
}				t_named_builtin;

# define BUILTIN_COUNT 8

int				execute_command_from_path(char *command_path, char **args,
					char **env);
int				try_to_execute_command_on_folder(char *path, char *command,
					char **args, char **env);
char			**get_args_from_tokens(t_token_reader *tr, size_t start);
t_command		init_command(void);
void			get_command_from_tokens(t_command *command);
int				execute_command_string_form(char *command, char **args,
					t_env_var_list *env_vars);
int				execute_command(t_command *command, t_env_var_list *env_vars);
t_token_reader	get_tokens_of_command(t_token_reader *exp, size_t start_token);
t_sentence		init_sentence(void);
t_sentence		parse_sentence(t_token_reader *tr);
void			open_pipes(t_sentence *sentence);
int				execute_sentence(t_sentence *sentence,
					t_env_var_list *env_vars);
int				parse_commands_of_sentence(t_sentence *sentence,
					t_token_reader *tr);
void			execute(char *command, t_env_var_list *env_vars);
void			set_redirect_type(t_command *command);
void			set_redirect_names(t_command *command);
void			builtin_authors(char **args, t_env_var_list *env_vars);
void			builtin_echo(char **args, t_env_var_list *env_vars);
void			builtin_exit(char **args, t_env_var_list *env_vars);
void			builtin_export(char **vars_to_export, t_env_var_list *env_vars);
void			builtin_cd(char **args, t_env_var_list *env_vars);
void			builtin_env(char **args, t_env_var_list *env_vars);
void			builtin_pwd(char **args, t_env_var_list *env_vars);
void			builtin_unset(char **args, t_env_var_list *env_vars);
void			read_until_line(int out_fd, char *limit);
void			destroy_sentence(t_sentence *sentence);
void			destroy_command(t_command *command);
void			open_command_pipe(t_sentence *sentence, size_t i);
void			open_command_out_redirection(t_command *command);
void			open_command_out_append_redirection(t_command *command);
void			open_command_in_delimiter_redirection(t_sentence *sentence,
					size_t i);
void			open_command_in_redirection(t_command *command);

static const	t_named_builtin
				g_builtins[BUILTIN_COUNT] = {
	{builtin_authors, "authors"},
	{builtin_echo, "echo"},
	{builtin_exit, "exit"},
	{builtin_export, "export"},
	{builtin_cd, "cd"},
	{builtin_env, "env"},
	{builtin_pwd, "pwd"},
	{builtin_unset, "unset"},
};

#endif
