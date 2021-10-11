/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:21:37 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/11 16:21:38 by javgonza         ###   ########.fr       */
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

typedef struct s_env_var_list
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
}				t_env_var_list;

typedef struct s_minishell_data
{
	int				error_code;
	int				cancelling_command;
	int				executing_command;
	int				command_exists;
}				t_minishell_data;

extern t_minishell_data	g_minishell_data;

void				init_minishell_data(void);
t_env_var_list		init_env_var_list(void);
void				copy_env_variables(t_env_var_list *env_vars, char **env);
void				set_term(t_env_var_list *env_vars, char *name, char *value);
void				set_term_program(t_env_var_list *env_vars, char *name,
						char *value);
void				set_shell(t_env_var_list *env_vars, char *name,
						char *value);
t_env_variable		str_to_env_var(char *var);
void				load_extra_variable(t_env_var_list *env_vars,
						char *new_var);
void				print_env_vars(t_env_var_list *env_vars);
void				free_env_var_list(t_env_variable *old_vars);
t_env_variable		*find_env_var(t_env_var_list *env_vars, char *name);
t_env_variable		*set_variable(t_env_var_list *env_vars, char *name,
						char *value);
t_env_variable		*find_default_var(t_env_var_list *env_vars, char *name);
t_env_variable		*find_extra_var(t_env_var_list *env_var, char *name);
void				export_var(t_env_var_list *env_vars, char *name);
void				set_path(t_env_var_list *env_vars, char *name, char *value);
void				set_home(t_env_var_list *env_vars, char *name, char *value);
void				load_env_variable(t_env_var_list *env_vars, char *var);
void				set_pwd(t_env_var_list *env_vars, char *name, char *value);
char				**env_vars_to_arr(t_env_var_list *env_vars);
char				*envvar_to_str(t_env_variable *envvar);
void				increment_shell_level(t_env_var_list *env_vars);

#endif
