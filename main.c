/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:29:57 by juthierr          #+#    #+#             */
/*   Updated: 2017/07/09 01:24:50 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "stdio.h"

int				ft_mem(struct dirent *dp, t_env *env)
{
	t_mem		*new;

	env->mem = env->first;
	if (env->mem->name == NULL)
	{
		if (!(env->mem->name = ft_strdup(dp->d_name)))
			return (0);
		env->mem->type = dp->d_type;
		env->mem->next = NULL;
		return (1);
	}
	while (env->mem->next != NULL)
	{
		env->mem = env->mem->next;
	}
	if (!(new = malloc(sizeof(t_list))))
		return (0);
	if (!(new->name = ft_strdup(dp->d_name)))
		return (0);
	new->type = dp->d_type;
	new->next = NULL;
	env->mem->next = new;
	return (1);
}

int				ft_recur(t_env *env, DIR *dir, struct dirent *dp, char *path)
{
	dir = opendir(path);
	while ((dp = readdir(dir)) != NULL)
	{
		ft_mem(dp, env);
		if(dp->d_type == DT_DIR)
		{
			if(dp->d_name[0] != '.')
			{
				ft_putstr(ft_strcat(dp->d_name, "\t"));
				ft_recur(env, dir, dp, dp->d_name);
			}
		}
		while (env->mem->next != NULL)
		{
			if()
			ft_putstr(ft_strcat(env->mem->name, "\t"));
			env->mem = env->mem->next;
		}
		ft_putstr(ft_strcat(env->mem->name, "\t"));
	}
	closedir(dir);
	return(0);
}

int main(int ac, char **av)
{
	t_env	*env;
	t_mem *mem;
	DIR *dir;
	struct dirent *dp;
	struct stat		*info;

	env = (t_env*)malloc(sizeof(t_env));
	mem = malloc(sizeof(t_mem));
	if (ac == 1)
	{
		env->first = mem;
		env->mem = mem;
		mem->type = NULL;
		mem->name = NULL;
		mem->next = NULL;
		ft_recur(env, dir, dp, ".");
		//dir = opendir(".");
		//while((dp = readdir(dir)) != NULL)
		//{
		//	ft_mem(mem, dp);
		//	if (dp->d_name[0] != '.')
		//		ft_putstr(ft_strcat(dp->d_name, "\t\t"));
			//stat(dp->d_name, info);
			//printf("%llu\n", dp->d_ino);
		}
		closedir(dir);
	return (0);
}
