/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:45:36 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/08 20:45:38 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

int		ft_lst_sort(t_mem *lst, struct dirent *dp, t_env *env)
{
	t_mem *tmp1;
	t_mem *tmp2;

	tmp1 = (t_mem *)malloc(sizeof(t_mem));
	tmp2->next = lst->next;
	tmp1->name = ft_strdup(dp->d_name);
	while (lst->next != NULL)
	{
		if ((ft_strcmp(lst->name, dp->d_name)) > 0)
		{
			tmp1->next = lst;
			tmp2->next = tmp1;
			return (0);
		}
		tmp2 = lst;
		lst = lst->next;
	}
	if((ft_strcmp(lst->name, dp->d_name)) <= 0)
	{
		tmp1->next = NULL;
		lst->next = tmp1;
		return (0);
	}
	else
	{
		tmp2 = lst;
		tmp1->next = tmp2;
		lst = tmp1;
		return (0);
	}
}

void	ft_mem(t_mem *lst, struct dirent *dp, t_env *env)
{
	if (lst->name == NULL)
	{
		lst->name = ft_strdup(dp->d_name);
		lst->next = NULL;
	}
	else
	{
		ft_lst_sort(lst, dp, env);
	}
}

void	ft_affichage(lst)
{

}

void	make_ls(char *path, t_env *env)
{
	t_mem			*lst;
	struct dirent	*dp;
	DIR				*dir;

	if (!(lst = (t_mem*)malloc(sizeof(t_mem))))
	{
		ft_putendl_fd("malloc error", 2);
		exit (0);
	}
	dir = opendir(path);
	while ((dp = readdir(dir)) != NULL)
	{
		ft_mem(lst, dp, env);
		ft_affichage();
	}
	closedir(dir);
}