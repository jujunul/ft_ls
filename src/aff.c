/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:17:32 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/27 16:25:24 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_puttype(struct stat buf)
{
	if (S_ISREG(buf.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(buf.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(buf.st_mode))
		ft_putchar('l');
	else if (S_ISBLK(buf.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(buf.st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(buf.st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(buf.st_mode))
		ft_putchar('s');
}

void	ft_print_permission(struct stat buf)
{
	ft_puttype(buf);
	ft_putstr((buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWUSR) ? "w" : "-");
	if ((!(buf.st_mode & S_IXUSR)) && (buf.st_mode & S_ISUID))
		ft_putchar('S');
	else if ((buf.st_mode & S_IXUSR) && (buf.st_mode & S_ISUID))
		ft_putchar('s');
	else
		ft_putstr((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWGRP) ? "w" : "-");
	if ((!(buf.st_mode & S_IXGRP)) && (buf.st_mode & S_ISUID))
		ft_putchar('S');
	else if ((buf.st_mode & S_IXGRP) && (buf.st_mode & S_ISUID))
		ft_putchar('s');
	else
		ft_putstr((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWOTH) ? "w" : "-");
	if ((!(buf.st_mode & S_IXOTH)) && (buf.st_mode & S_ISVTX))
		ft_putchar('T');
	else if ((buf.st_mode & S_IXOTH) && (buf.st_mode & S_ISVTX))
		ft_putchar('t');
	else
		ft_putstr((buf.st_mode & S_IXOTH) ? "x" : "-");
}

void	ft_print_uid(struct stat buf)
{
	struct passwd *tmp;

	if ((tmp = getpwuid(buf.st_uid)) == NULL)
		ft_putnbr(buf.st_uid);
	else
		ft_putstr(tmp->pw_name);
}

void	ft_print_gid(struct stat buf)
{
	struct group *tmp;

	if ((tmp = getgrgid(buf.st_gid)) == NULL)
		ft_putnbr(buf.st_gid);
	else
		ft_putstr(tmp->gr_name);
}

void	ft_affichage(t_mem *lst, t_env *env, char *path)
{
	if (env->option[l] == TRUE)
	{
		ft_get_total(lst, path, env);
		aff_opt_l(lst, env, path);
		return ;
	}
	ft_putincol(lst, env);
}
