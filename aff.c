/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:17:32 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/18 10:17:33 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_puttype(struct stat buf)
{
	if (S_ISDIR(buf.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(buf.st_mode))
		ft_putchar('l');
	else
		ft_putchar('-');
}

void	ft_print_permission(struct stat buf)
{
	ft_puttype(buf);
	ft_putstr((buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXOTH) ? "x" : "-");
}

void	ft_print_uid(struct stat buf)
{
	struct passwd *tmp;

	tmp = getpwuid(buf.st_uid);
	ft_putstr(tmp->pw_name);
}

void	ft_print_gid(struct stat buf)
{
	struct group *tmp;

	tmp = getgrgid(buf.st_gid);
	ft_putstr(tmp->gr_name);
}

void	ft_putnol(char *str)
{
	str = str + 4;
	while (*str != '\0' && *str != '\n')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_affichage(t_mem *lst, t_env *env, char *path)
{
	if (env->option[l] == true)
	{
		aff_opt_l(lst, env, path);
		return ;
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
			ft_putstr("\t");
			lst = lst->next;
		}
	}
	ft_putstr("\n");
}
