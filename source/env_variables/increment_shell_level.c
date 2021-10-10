/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_shell_level.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:50:56 by javgonza          #+#    #+#             */
/*   Updated: 2021/10/10 11:20:31 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_variables.h"
#include "../../libft/incs/libft.h"

void	increment_shell_level(void)
{
	char			*tmp;
	char			*new_value;
	t_env_variable	new_var;
	int				num_val;
	t_env_variable	*shlvl;

	shlvl = find_env_var("SHLVL");
	if (shlvl == NULL)
	{
		load_env_variable("SHLVL=1");
		export_var("SHLVL");
		return ;
	}
	tmp = shlvl->value;
	num_val = ft_atoi(tmp);
	num_val++;
	new_value = ft_itoa(num_val);
	new_var.name = "SHLVL";
	new_var.value = new_value;
	tmp = envvar_to_str(&new_var);
	load_env_variable(tmp);
	free(tmp);
	free(new_value);
}
