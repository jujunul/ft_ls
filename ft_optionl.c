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

void	ft_aff_all(struct stat buf, t_mem *lst)
{
	ft_print_permission(buf);
	ft_putstr("   ");
	ft_putnbr(buf.st_nlink);
	ft_putstr("  ");
	ft_print_uid(buf);
	ft_putstr("  ");
	ft_print_gid(buf);
	ft_putstr("  ");
	ft_putnbr(buf.st_size);
	ft_putstr("\t");
	ft_putnol(ctime(&buf.st_mtime));
	ft_putstr(" ");
	ft_putstr(lst->name);
	ft_putstr("\n");
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
		ft_aff_all(buf, lst);
		lst = lst->next;
	}
}
