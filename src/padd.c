/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:44:16 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/24 18:44:18 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_printnamefile(char *path)
{
	if (ft_strcmp(path, ".") == 0)
		return ;
	ft_putchar('\n');
	ft_putendl(ft_strjoin(path, ":"));
}

void	ft_free_list(t_mem *lst)
{
	if (lst->next)
		ft_free_list(lst->next);
	free(lst);
}

int		ft_isfile(char *path)
{
	struct stat buf;

	lstat(path, &buf);
	if (S_ISDIR(buf.st_mode))
		return (1);
	else
		return (0);
}

void	ft_get_total(t_mem *lst, char *path, t_env *env)
{
	int			test;
	struct stat buf;

	test = 0;
	while (lst)
	{
		if (lst->name[0] == '.' && env->option[a] == FALSE)
		{
			lst = lst->next;
			continue ;
		}
		lstat(ft_strcat_path(path, lst->name), &buf);
		test += buf.st_blocks;
		lst = lst->next;
	}
	ft_printotal(test);
}

void	ft_padding_mfile(int t, char **av, int i)
{
	struct stat buf;

	lstat(av[i - 1], &buf);
	if (t != 1 && S_ISDIR(buf.st_mode))
	{
		ft_putstr("\n");
		ft_putstr(av[i - 1]);
		ft_putendl(":");
	}
}
