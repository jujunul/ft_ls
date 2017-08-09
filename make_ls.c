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

int		ft_lst_sort(t_mem *lst, struct dirent *dp)
{
	t_mem *tmp1;
	t_mem *tmp2;

	tmp1 = (t_mem*)malloc(sizeof(t_mem));
	tmp2 = (t_mem*)malloc(sizeof(t_mem));
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

void	ft_sort_time(t_mem *lst, struct dirent *dp, t_env *env)
{
	//faire le sort pars le temps dans stat st_atime or st_ctime;
}


void	ft_mem(t_mem *lst, struct dirent *dp, t_env *env)
{
	if (lst->name == NULL)
	{
		lst->name = ft_strdup(dp->d_name);
		lst->next = NULL;
		return ;
	}
	else
	{
		if (env->option[t] == true)
			ft_sort_time(lst, dp)
		ft_lst_sort(lst, dp, env);
		return ;
	}
}

void	ft_affichage(t_mem *lst)
{
	while (lst->next != NULL)
	{
		printf("%s\n", lst->name);
		lst = lst->next;
	}
	printf("%s\n", lst->name);
}

void	make_ls(char *path, t_env *env)
{
	t_mem			*lst;
	struct dirent	*dp;
	DIR				*dir;
	t_mem			*first;

	if (!(lst = (t_mem*)malloc(sizeof(t_mem))))
	{
		ft_putendl_fd("malloc error", 2);
		exit (0);
	}
	lst->next = NULL;
	lst->name = ft_strnew(1);
	dir = opendir(path);
	while ((dp = readdir(dir)) != NULL)
	{
		ft_mem(lst, dp, env);
		if (env->option[R] == true && dp->d_type == S_ISDIR)
			make_ls(ft_strcat_path(path, dp->d_name), env);
	}
	if (env->option[r] == true)
		ft_lst_reverse(lst, dp);
	ft_affichage(lst);
	ft_ls_recur(lst, env);
	closedir(dir);
}