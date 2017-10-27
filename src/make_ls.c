/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:45:36 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/27 16:21:56 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_mem	*ft_mem(t_mem *lst, struct dirent *dp, t_env *env)
{
	if (lst->name == NULL)
	{
		if (!(lst->name = ft_strdup(dp->d_name)))
			exit(EXIT_FAILURE);
		lst->next = NULL;
	}
	else
	{
		if (env->option[t] == TRUE && env->option[r] == FALSE)
			lst = ft_sort_time(lst, dp);
		else if (env->option[t] == TRUE && env->option[r] == TRUE)
			lst = ft_sort_time_r(lst, dp);
		else if (env->option[t] == FALSE && env->option[r] == TRUE)
			lst = ft_lst_sort_r(lst, dp);
		else if (env->option[t] == FALSE && env->option[r] == FALSE)
			lst = ft_lst_sort(lst, dp);
	}
	return (lst);
}

int		ft_error_directory(char *path, t_env *env)
{
	struct stat buf;

	if (-1 != lstat(path, &buf))
	{
		ft_aff_on_file(path, env);
		return (1);
	}
	else
	{
		ft_putstr_fd(path, 2);
		ft_putendl_fd(" : No such file or directory", 2);
		return (1);
	}
}

void	ft_recur(t_mem *lst, t_env *env, char *path)
{
	struct stat	buf;

	while (lst)
	{
		lstat(ft_strcat_path(path, lst->name), &buf);
		if ((ft_strcmp(lst->name, ".") == 0) ||
				(ft_strcmp(lst->name, "..") == 0))
			;
		else if (lst->name[0] == '.' && env->option[a] == FALSE)
			;
		else if (env->option[R] == TRUE && S_ISDIR(buf.st_mode) &&
				!S_ISLNK(buf.st_mode))
		{
			make_ls(ft_strcat_path(path, lst->name), env);
		}
		lst = lst->next;
	}
}

t_mem	*ft_read(t_env *env, t_mem *lst)
{
	struct dirent	*dp;

	while ((dp = readdir(env->dir)) != NULL)
		lst = ft_mem(lst, dp, env);
	closedir(env->dir);
	return (lst);
}

void	make_ls(char *path, t_env *env)
{
	t_mem			*lst;

	if (!(lst = (t_mem*)malloc(sizeof(t_mem))))
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	lst->name = NULL;
	lst->next = NULL;
	if ((env->dir = opendir(path)) == NULL)
	{
		if (ft_error_directory(path, env))
			return ;
	}
	lst = ft_read(env, lst);
	if (env->option[R] == TRUE)
		ft_printnamefile(path);
	ft_affichage(lst, env, path);
	ft_recur(lst, env, path);
	ft_free_list(lst);
}
