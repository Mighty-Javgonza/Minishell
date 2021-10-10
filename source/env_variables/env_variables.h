/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:05:49 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:29 by javgonza         ###   ########.fr       */
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
	t_env_variable	path;
	t_env_variable	pwd;
	t_env_variable	home;
	size_t			default_env_var_count;
	t_env_variable	*extra_variables;
	size_t			extra_variables_size;
	int				error_code;
	int				cancelling_command;
	int				executing_command;
	int				command_exists;
}				t_minishell_data;

extern t_minishell_data	g_minishell_data;
t_minishell_data		g_minishell_data;

void				init_minishell_data(void);
void				copy_env_variables(char **env);
void				set_term_program(char *name, char *value);
void				set_shell(char *name, char *value);
void				set_term(char *name, char *value);
t_env_variable		str_to_env_var(char *var);
void				load_extra_variable(char *new_var);
void				print_env_vars(void);
void				free_env_var_list(t_env_variable *old_vars);
t_env_variable		*find_env_var(char *name);
t_env_variable		*set_variable(char *name, char *value);
t_env_variable		*find_default_var(char *name);
t_env_variable		*find_extra_var(char *name);
void				export_var(char *name);
void				set_path(char *name, char *value);
void				set_home(char *name, char *value);
void				load_env_variable(char *var);
void				set_pwd(char *name, char *value);
char				**env_vars_to_arr(void);
char				*envvar_to_str(t_env_variable *envvar);
void				increment_shell_level(void);

#endif
