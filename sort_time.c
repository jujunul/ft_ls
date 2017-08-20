/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:17:25 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/20 14:17:27 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_mem	*asmr_sort_time(t_mem *lst, t_mem *tmp, t_mem *new, struct dirent *dp)
{
	struct stat buf;
	struct stat tp;
	t_mem		*prev;

	prev = NULL;
	lstat(dp->d_name, &tp);
	while (tmp != NULL)
	{
		lstat(tmp->name, &buf);
		if ((buf.st_mtimespec.tv_sec - tp.st_mtimespec.tv_sec) < 0)
		{
			new->next = tmp;
			if (prev == NULL)
			{
				lst = new;
				break ;
			}
			prev->next = new;
			break ;
		}
		ft_simpletest(tmp, new);
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

t_mem	*ft_sort_time(t_mem *lst, struct dirent *dp)
{
	t_mem		*tmp;
	t_mem		*prev;
	t_mem		*new;
	struct stat buf;
	struct stat tp;

	new = (t_mem*)malloc(sizeof(t_mem));
	tmp = lst;
	prev = NULL;
	lstat(dp->d_name, &tp);
	new->name = ft_strdup(dp->d_name);
	return (asmr_sort_time(lst, tmp, new, dp));
}

t_mem	*asmr_sort_time_r(t_mem *lst, t_mem *tmp, t_mem *new, struct dirent *dp)
{
	t_mem		*prev;
	struct stat buf;
	struct stat tp;

	prev = NULL;
	lstat(dp->d_name, &tp);
	while (tmp != NULL)
	{
		lstat(tmp->name, &buf);
		if ((buf.st_mtimespec.tv_sec - tp.st_mtimespec.tv_sec) >= 0)
		{
			new->next = tmp;
			if (prev == NULL)
			{
				lst = new;
				break ;
			}
			prev->next = new;
			break ;
		}
		ft_simpletest(tmp, new);
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

t_mem	*ft_sort_time_r(t_mem *lst, struct dirent *dp)
{
	t_mem		*tmp;
	t_mem		*prev;
	t_mem		*new;
	struct stat buf;
	struct stat tp;

	new = (t_mem*)malloc(sizeof(t_mem));
	tmp = lst;
	prev = NULL;
	new->name = ft_strdup(dp->d_name);
	return (asmr_sort_time_r(lst, tmp, new, dp));
}
