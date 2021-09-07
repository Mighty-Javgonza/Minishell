/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/07 15:43:42 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VARIABLES_H
# define ENV_VARIABLES_H

# include "../../libft/incs/libft.h"

typedef struct s_env_variable
{
	char			*name;
	char			*value;
	unsigned int	is_local : 1;
}				t_env_variable;

typedef struct s_minishell_data
{
	t_env_variable	term_program;
	t_env_variable	term;
	t_env_variable	shell;
	t_env_variable	tmpdir;
	t_env_variable	apple_pubsub_socket_render;
	t_env_variable	term_program_version;
	t_env_variable	term_session_id;
	t_env_variable	user;
	t_env_variable	command_mode;
	t_env_variable	ssh_auth_sock;
	t_env_variable	__cf_user_text_encoding;
	t_env_variable	path;
	t_env_variable	pwd;
	t_env_variable	lang;
	t_env_variable	iterm_profile;
	t_env_variable	xpc_flags;
	t_env_variable	xpc_service_name;
	t_env_variable	shlvl;
	t_env_variable	home;
	t_env_variable	colorfgbg;
	t_env_variable	lc_terminal_version;
	t_env_variable	iterm_session_id;
	t_env_variable	logname;
	t_env_variable	lc_terminal;
	t_env_variable	securitysessionid;
	t_env_variable	colorterm;
	t_env_variable	_;
	size_t			default_env_var_count;
	t_env_variable	*extra_variables;
	size_t			extra_variables_size;
}				t_minishell_data;



extern t_minishell_data	g_minishell_data;

void	init_minishell_data();
void	copy_env_variables(char **env);
t_minishell_data g_minishell_data;;
void	load_env_variable(char *var);

void	set_term_program(char *name, char *value);

void	set_shell(char *name, char *value);
void	set_term(char *name, char *value);

t_env_variable	str_to_env_var(char *var);
void	load_extra_variable(char *new_var);



void	print_env_vars();

void	free_env_var_list(t_env_variable *old_vars);

t_env_variable	*find_env_var(char *name);

t_env_variable	*set_variable(char *name, char *value);

t_env_variable	*find_default_var(char *name);
t_env_variable	*find_extra_var(char *name);

void	export_var(char *name);
#endif
