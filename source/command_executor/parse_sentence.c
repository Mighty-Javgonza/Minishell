/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sentence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:38:38 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/15 14:52:08 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"

static void	add_command(t_sentence *sentence, t_command command)
{
	t_command	*old_commands;

	old_commands = sentence->commands;
	sentence->commands = malloc(sizeof(*sentence->commands) * (sentence->command_count + 1));
	ft_memmove(sentence->commands, old_commands, sizeof(*sentence->commands) * sentence->command_count);
	sentence->commands[sentence->command_count] = command;
	sentence->command_count++;
}

t_sentence	parse_sentence(t_token_reader *tr)
{
	t_command		command;
	t_sentence		sentence;
	size_t			tokens_read;

	sentence = init_sentence();
	tokens_read = 0;
	command.tr = get_tokens_of_command(tr, 0);
	while (command.tr.token_count > 0)
	{
		tokens_read += command.tr.token_count + 1;
		command.redirect_type = tr->tokens[tokens_read - 1].type;
		add_command(&sentence, command);
		command = init_command();	
		command.tr = get_tokens_of_command(tr, tokens_read);
	}
	open_pipes(&sentence);
	return (sentence);
}
