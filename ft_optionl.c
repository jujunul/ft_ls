/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optionl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 22:13:52 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/19 22:13:55 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"


void	ft_putname(char *name, char *path, struct stat buf)
{
	char *linkname;

	if (S_ISLNK(buf.st_mode))
	{
		if(!(linkname = (char *)malloc(buf.st_size + 1)))
			exit(0);
		readlink(ft_strcat_path(path, name), linkname, buf.st_size + 1);
		linkname[buf.st_size] = '\0';
		ft_putstr(name);
		ft_putstr(" -> ");
		ft_putstr(linkname);
	}
	else
		ft_putstr(name);
}

void	ft_aff_all(struct stat buf, t_mem *lst, char *path)
{
	ft_print_permission(buf);
	ft_putstr("\t");
	ft_putnbr(buf.st_nlink);
	ft_putstr("\t");
	ft_print_uid(buf);
	ft_putstr("\t");
	ft_print_gid(buf);
	ft_putstr("\t");
	ft_putnbr(buf.st_size);
	ft_putstr("\t");
	ft_putnol(ctime(&buf.st_mtime));
	ft_putstr(" ");
	ft_putname(lst->name, path, buf);
	ft_putstr("\n");
}

void	aff_opt_lf(t_mem *lst, t_env *env, char *path)
{
	struct stat buf;

	while (lst)
	{
		if (lst->name[0] == '.' && env->option[a] == false)
		{
			lst = lst->next;
			continue ;
		}
		lstat(path, &buf);
		ft_aff_all(buf, lst, path);
		lst = lst->next;
	}
}

void	ft_affichage_file(t_mem *lst, t_env *env, char *path)
{
	if (env->option[l] == true)
	{
		aff_opt_lf(lst, env, path);
		exit(1);
	}
	while (lst)
	{
		if (lst->name[0] == '.' && env->option[a] == false)
		{
			lst = lst->next;
			continue ;
		}
		else
		{
			ft_putstr(lst->name);
			ft_putstr("   ");
			lst = lst->next;
		}
	}
	ft_putstr("\n");
}

void	ft_aff_on_file(char *path, t_env *env)
{
	t_mem *lst;

	lst = (t_mem *)malloc(sizeof(t_mem));
	lst->name = (ft_strrchr(path, 47) + 1);
	lst->next = NULL;
	ft_affichage_file(lst, env, path);
}

void	aff_opt_l(t_mem *lst, t_env *env, char *path)
{
	struct stat buf;

	while (lst)
	{
		if (lst->name[0] == '.' && env->option[a] == false)
		{
			lst = lst->next;
			continue ;
		}
		lstat(ft_strcat_path(path, lst->name), &buf);
		ft_aff_all(buf, lst, path);
		lst = lst->next;
	}
}
