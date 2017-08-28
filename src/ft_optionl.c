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

void	aff_opt_lf(t_mem *lst, t_env *env, char *path)
{
	struct stat buf;

	while (lst)
	{
		if (lst->name[0] == '.' && env->option[a] == FALSE)
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
	if (env->option[l] == TRUE)
	{
		aff_opt_lf(lst, env, path);
		return ;
	}
	while (lst)
	{
		if (lst->name[0] == '.' && env->option[a] == FALSE)
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

void	ft_printotal(int total)
{
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

void	aff_opt_l(t_mem *lst, t_env *env, char *path)
{
	struct stat buf;

	while (lst)
	{
		if (lst->name[0] == '.' && env->option[a] == FALSE)
		{
			lst = lst->next;
			continue ;
		}
		lstat(ft_strcat_path(path, lst->name), &buf);
		ft_aff_all(buf, lst, path);
		lst = lst->next;
	}
}
