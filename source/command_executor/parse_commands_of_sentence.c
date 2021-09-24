/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands_of_sentence.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:27:08 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:29:47 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"

static void	add_command(t_sentence *sentence, t_command command)
{
	t_command	*old_commands;

	old_commands = sentence->commands;
	sentence->commands = malloc(
			sizeof(*sentence->commands) * (sentence->command_count + 1));
	ft_memmove(sentence->commands, old_commands,
		sizeof(*sentence->commands) * sentence->command_count);
	sentence->commands[sentence->command_count] = command;
	sentence->command_count++;
}

void	parse_commands_of_sentence(t_sentence *sentence, t_token_reader *tr)
{
	t_command		command;
	size_t			tokens_read;

	tokens_read = 0;
	command = init_command();
	command.tr = get_tokens_of_command(tr, 0);
	set_redirect_type(&command);
	set_redirect_names(&command);
	while (command.tr.token_count > 0 && tokens_read < tr->token_count)
	{
		tokens_read += command.tr.token_count;
		if (tr->tokens[tokens_read].type != TOKEN_TYPE_NORMAL)
			command.redirect_type |= tr->tokens[tokens_read].type;
		set_redirect_type(&command);
		add_command(sentence, command);
		if (tokens_read < tr->token_count)
		{
			command = init_command();
			command.tr = get_tokens_of_command(tr, tokens_read + 1);
			set_redirect_type(&command);
			set_redirect_names(&command);
		}
	}
}
