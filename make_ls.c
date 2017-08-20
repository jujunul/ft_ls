/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:45:36 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/20 17:48:07 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

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
			lst = ft_sort_time_r(lst, dp);
		else if (env->option[t] == false && env->option[r] == true)
			lst = ft_lst_sort_r(lst, dp);
		else if (env->option[t] == false && env->option[r] == false)
			lst = ft_lst_sort(lst, dp);
	}
	return (lst);
}

void	ft_error_directory(DIR *dir, char *path)
{
	struct stat buf;

	if (-1 != lstat(path, &buf))
	{
		ft_putendl((ft_strrchr(path, 47) + 1));
		perror(path);
		exit(EXIT_FAILURE);
	}
}

void	ft_protect_stat(char *path, struct dirent *dp, struct stat buf)
{
	if (-1 == lstat(ft_strcat_path(path, dp->d_name), &buf))
	{
		perror(dp->d_name);
		exit(EXIT_FAILURE);
	}
}

void	ft_read(t_env *env, char *path, struct dirent *dp, t_mem *lst)
{
	while ((dp = readdir(env->dir)) != NULL)
	{
		lst = ft_mem(lst, dp, env);
		ft_protect_stat(path, dp, env->buf);
		if ((ft_strcmp(dp->d_name, ".") == 0) ||
				(ft_strcmp(dp->d_name, "..") == 0))
			continue ;
		else if (dp->d_name[0] == '.' && env->option[a] == false)
			continue ;
		else if (env->option[R] == true && S_ISDIR(env->buf.st_mode))
			make_ls(ft_strcat_path(path, dp->d_name), env);
	}
}

void	make_ls(char *path, t_env *env)
{
	t_mem			*lst;
	struct dirent	*dp;
	t_mem			*first;

	if (!(lst = (t_mem*)malloc(sizeof(t_mem))))
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	lst->name = NULL;
	lst->next = NULL;
	if ((!(env->dir = opendir(path))))
	{
		perror(path);
		exit(EXIT_FAILURE);
	}
	ft_read(env, path, dp, lst);
	ft_affichage(lst, env, path);
	closedir(env->dir);
}
