/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_until_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:22:17 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 10:09:28 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"
#include "../utils/utils.h"
#include <readline/readline.h>

void	read_until_line(int out_fd, char *limit)
{
	char	*line;

	line = NULL;
	line = readline(">");
	while (line != NULL && !streq(line, limit))
	{
		write(out_fd, line, ft_strlen(line));
		write(out_fd, "\n", 1);
		free(line);
		line = readline(">");
	}
	free(line);
}
