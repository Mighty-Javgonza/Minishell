/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_until_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:22:17 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/26 11:40:52 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_executor.h"
#include "../../libft/incs/libft.h"
#include "../utils/utils.h"

void	read_until_line(int out_fd, char *limit)
{
	char	*line;

	line = NULL;
	write(STDOUT_FILENO, ">", 1);
	get_next_line(STDIN_FILENO, &line);
	while (!streq(line, limit))
	{
		write(out_fd, line, ft_strlen(line));
		write(out_fd, "\n", 1);
		write(STDOUT_FILENO, ">", 1);
		get_next_line(STDIN_FILENO, &line);
	}
}
