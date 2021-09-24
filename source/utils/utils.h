/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:40:47 by javgonza          #+#    #+#             */
/*   Updated: 2021/09/24 08:50:10 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		streq(char *a, char *b);
int		is_charset(char c, char *set);
char	*strcharset(char *string, char *set);
char	*strcharset_n(char *string, char *set);
char	*str_in_ptrs(char *start, char *end);
char	*str_unsc_set_n(char *string, char *set);
char	*str_unsc_set(char *string, char *set);
char	*delete_substr(char *base, char *start, char *end);
char	*insert_substr(char *base, char *start, char *insert);
char	*subst_substr(char *base, char *start, char *end, char *insert);
void	delete_char(char **str, char *delete);

#endif
