/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:52:31 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/20 13:52:33 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_simpletest(t_mem *tmp, t_mem *new)
{
	if (tmp->next == NULL)
	{
		tmp->next = new;
		new->next = NULL;
	}
}

t_mem	*asmr_lst_sort_r(t_mem *lst, t_mem *tmp, t_mem *new, struct dirent *dp)
{
	t_mem *prev;

	prev = NULL;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, dp->d_name) <= 0)
		{
			if (prev == NULL)
			{
				new->next = tmp;
				lst = new;
				break ;
			}
			else
			{
				new->next = tmp;
				prev->next = new;
				break ;
			}
		}
		ft_simpletest(tmp, new);
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

t_mem	*ft_lst_sort_r(t_mem *lst, struct dirent *dp)
{
	t_mem *tmp;
	t_mem *prev;
	t_mem *new;

	new = (t_mem*)malloc(sizeof(t_mem));
	tmp = lst;
	prev = NULL;
	new->name = ft_strdup(dp->d_name);
	return (asmr_lst_sort_r(lst, tmp, new, dp));
}

t_mem	*asmr_lst_sort(t_mem *lst, t_mem *new, t_mem *tmp, struct dirent *dp)
{
	t_mem *prev;

	prev = NULL;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, dp->d_name) > 0)
		{
			if (prev == NULL)
			{
				new->next = tmp;
				lst = new;
				break ;
			}
			else
			{
				new->next = tmp;
				prev->next = new;
				break ;
			}
		}
		ft_simpletest(tmp, new);
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

t_mem	*ft_lst_sort(t_mem *lst, struct dirent *dp)
{
	t_mem *tmp;
	t_mem *prev;
	t_mem *new;

	new = (t_mem*)malloc(sizeof(t_mem));
	tmp = lst;
	prev = NULL;
	new->name = ft_strdup(dp->d_name);
	return (asmr_lst_sort(lst, new, tmp, dp));
}
