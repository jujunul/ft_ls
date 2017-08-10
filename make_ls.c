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

t_mem		*ft_lst_sort(t_mem *lst, struct dirent *dp)
{
	t_mem *tmp;
	t_mem *prev;
	t_mem *new;

	new = (t_mem*)malloc(sizeof(t_mem));
	tmp = lst;
	prev = NULL;
	new->name = ft_strdup(dp->d_name);
	while (tmp !=NULL)
	{
		if (ft_strcmp(tmp->name, dp->d_name) > 0)
		{
			if(prev == NULL)
			{
				new->next = tmp;
				lst = new;
				break ;
			}
				else
			{
				new->next = tmp;
				prev->next = new;
				break;
			}
		}
		if (tmp->next == NULL)
		{
			tmp->next = new;
			new->next = NULL;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

t_mem		*ft_sort_time(t_mem *lst, struct dirent *dp)
{
	t_mem *tmp;
	t_mem *prev;
	t_mem *new;
	struct stat buf;
	struct stat tp;

	new = (t_mem*)malloc(sizeof(t_mem));
	tmp = lst;
	prev = NULL;
	lstat(dp->d_name, &tp);
	new->name = ft_strdup(dp->d_name);
	while (tmp != NULL)
	{
		lstat(tmp->name, &buf);
		if ((buf.st_mtimespec.tv_sec - tp.st_mtimespec.tv_sec) < 0)
		{
			if(prev == NULL)
			{
				new->next = tmp;
				lst = new;
				break ;
			}
				else
			{
				new->next = tmp;
				prev->next = new;
				break;
			}
		}
		if (tmp->next == NULL)
		{
			tmp->next = new;
			new->next = NULL;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

t_mem		*ft_sort_time_r(t_mem *lst, struct dirent *dp)
{
	t_mem *tmp;
	t_mem *prev;
	t_mem *new;
	struct stat buf;
	struct stat tp;

	new = (t_mem*)malloc(sizeof(t_mem));
	tmp = lst;
	prev = NULL;
	lstat(dp->d_name, &tp);
	new->name = ft_strdup(dp->d_name);
	while (tmp != NULL)
	{
		lstat(tmp->name, &buf);
		if ((buf.st_mtimespec.tv_sec - tp.st_mtimespec.tv_sec) >= 0)
		{
			if(prev == NULL)
			{
				new->next = tmp;
				lst = new;
				break ;
			}
				else
			{
				new->next = tmp;
				prev->next = new;
				break;
			}
		}
		if (tmp->next == NULL)
		{
			tmp->next = new;
			new->next = NULL;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

t_mem	*ft_mem(t_mem *lst, struct dirent *dp, t_env *env)
{
	if (lst->name == NULL)
	{
		lst->name = ft_strdup(dp->d_name);
		lst->next = NULL;
	}
	else
	{
		if (env->option[t] == true && env->option[r] == false)
			lst = ft_sort_time(lst, dp);
		else if (env->option[t] == true && env->option[r] == true)
			lst =ft_sort_time_r(lst, dp);
		else if (env->option[t] == false && env->option[r] == true)
			lst = ft_lst_sort_r(lst, dp);
		else if (env->option[t] == false && env->option[r] == false)
			lst = ft_lst_sort(lst, dp);
	}
	return (lst);
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
	struct stat 	buf;

	if (!(lst = (t_mem*)malloc(sizeof(t_mem))))
	{
		ft_putendl_fd("malloc error", 2);
		exit (0);
	}
	lst->name = NULL;
	lst->next = NULL;
	dir = opendir(path);
	while ((dp = readdir(dir)) != NULL)
	{
		lst = ft_mem(lst, dp, env);
		lstat(dp->d_name, &buf);
		if (env->option[R] == true && S_ISDIR(buf.st_mode))
			make_ls(ft_strcat_path(path, dp->d_name), env);
	}
	ft_affichage(lst);
	closedir(dir);
}