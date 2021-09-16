/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_interpreter.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:54:33 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/14 12:59:56 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_INTERPRETER_H
# define COMMAND_INTERPRETER_H

# define TOKEN_TYPE_NORMAL 0
# define TOKEN_TYPE_PIPE 1
# define TOKEN_TYPE_REDIRECT_INPUT 2
# define TOKEN_TYPE_REDIRECT_OUTPUT 3
# define TOKEN_TYPE_REDIRECT_OUTPUT_APPEND 4
# define TOKEN_TYPE_REDIRECT_INPUT_DELIMITER 5

# define TOKEN_SPECIAL_CHARS "|<>&"

# include <stdlib.h>

typedef struct s_token
{
	char			*value;
	unsigned int	type : 3;
	char			*end; //in original string
}				t_token;

typedef struct s_token_reader
{
	t_token	*tokens;
	size_t	token_count;
}				t_token_reader;

t_token	init_token();
t_token	get_first_token_from_string(char *string);
char	*get_token_end(char *token_start);
t_token_reader	read_tokens(char *string);


t_token_reader	init_token_reader();

void	add_token(t_token_reader *tr, t_token token);

t_token_reader	expand_tokens(t_token_reader *tr);
void	add_expansion_to_reader(t_token_reader *tr, t_token *token);

char	*get_first_escaped_char(char *string);

void	expand_variables(t_token *token);
#endif
