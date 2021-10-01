/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_interpreter.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/30 14:15:03 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_INTERPRETER_H
# define COMMAND_INTERPRETER_H

# define TOKEN_TYPE_NORMAL 0
# define TOKEN_TYPE_PIPE 0b1
# define TOKEN_TYPE_REDIRECT_INPUT 0b10
# define TOKEN_TYPE_REDIRECT_OUTPUT 0b100
# define TOKEN_TYPE_REDIRECT_OUTPUT_APPEND 0b1000
# define TOKEN_TYPE_REDIRECT_INPUT_DELIMITER 0b10000

# define TOKEN_SPECIAL_CHARS "|<>&"

# include <stdlib.h>

typedef struct s_token
{
	char			*value;
	unsigned int	type;
	char			*end;
}				t_token;

typedef struct s_token_reader
{
	t_token	*tokens;
	size_t	token_count;
}				t_token_reader;

t_token			init_token(void);
t_token			get_first_token_from_string(char *string);
char			*get_token_end(char *token_start);
t_token_reader	read_tokens(char *string);
t_token_reader	init_token_reader(void);
void			add_token(t_token_reader *tr, t_token token);
t_token_reader	expand_tokens(t_token_reader *tr);
void			add_expansion_to_reader(t_token_reader *tr, t_token *token);
char			*get_first_escaped_char(char *string);
void			expand_variables(t_token *token);
void	destroy_token(t_token *token);
void	destroy_token_reader(t_token_reader *tr);

#endif
