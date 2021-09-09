/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executor.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:49:32 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/09 13:17:38 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_EXECUTOR_H
# define COMMAND_EXECUTOR_H

# define MINISHELL_PROMPT "minishell dice:"

int	execute_command(char *command_path, char **args);


int	execute_command_from_path(char *command_path, char **args, char **env);

int	execute_command(char *command, char **args);
int	try_to_execute_command_on_folder(char *path, char *command, char **args, char **env);

#endif
