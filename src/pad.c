/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:23:57 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/27 16:25:59 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_putincol(t_mem *lst, t_env *env)
{
	int i;

	i = 0;
	while (lst)
	{
		if (lst->name[0] == '.' && env->option[a] == FALSE)
			lst = lst->next;
		else
		{
			i++;
			ft_putstr(lst->name);
			lst = lst->next;
			if (i == 4)
			{
				i = 0;
				ft_putchar('\n');
			}
			else
				ft_putchar('\t');
		}
	}
	ft_putchar('\n');
}
