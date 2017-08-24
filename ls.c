/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 01:24:52 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/24 01:24:55 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_putname(char *name, char *path, struct stat buf)
{
	char *linkname;

	if (S_ISLNK(buf.st_mode))
	{
		if (!(linkname = (char *)malloc(buf.st_size + 1)))
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

void	ft_printonlyyear(t_mem *lst, char *path)
{
	char		*str;
	int			i;
	struct stat buf;

	lstat(ft_strcat_path(path, lst->name), &buf);
	str = ctime(&buf.st_mtime);
	str = str + 4;
	i = 0;
	while (*str != '\n' && i < 6)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	i = 0;
	while (i < 9)
	{
		str++;
		i++;
	}
	while (*str != '\n')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_printonlymin(t_mem *lst, char *path)
{
	char		*str;
	int			i;
	struct stat buf;

	lstat(ft_strcat_path(path, lst->name), &buf);
	str = ctime(&buf.st_mtime);
	str = str + 4;
	i = 0;
	while (*str != '\n' && i < 12)
	{
		write(1, str, 1);
		str++;
		i++;
	}
}

void	ft_puttime(t_mem *lst, char *path)
{
	time_t		current_time;
	time_t		month;
	struct stat buf;

	current_time = time(0);
	month = 15552000;
	lstat(ft_strcat_path(path, lst->name), &buf);
	if (current_time - buf.st_mtime > month)
	{
		ft_printonlyyear(lst, path);
	}
	else
	{
		ft_printonlymin(lst, path);
	}
}

void	ft_aff_all(struct stat buf, t_mem *lst, char *path)
{
	struct stat test;

	ft_print_permission(buf);
	ft_putstr("\t");
	ft_putnbr(buf.st_nlink);
	ft_putstr("\t");
	ft_print_uid(buf);
	ft_putstr("\t");
	ft_print_gid(buf);
	ft_putstr("\t");
	if (S_ISCHR(buf.st_mode))
	{
		ft_putnbr(major(buf.st_rdev));
		ft_putchar(',');
		ft_putnbr(minor(buf.st_rdev));
	}
	else
		ft_putnbr(buf.st_size);
	ft_putstr("\t");
	ft_puttime(lst, path);
	ft_putstr(" ");
	ft_putname(lst->name, path, buf);
	ft_putstr("\n");
}
