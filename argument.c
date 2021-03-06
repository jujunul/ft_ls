/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lala.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:33:54 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/08 18:35:54 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		ft_init_arg(bool *option)
{
	option[R] = false;
	option[a] = false;
	option[l] = false;
	option[r] = false;
	option[t] = false;
	option[un] = false;
}

int			ft_filloption(char avc, bool *option)
{
	if (avc == 'R')
		option[R] = true;
	else if (avc == 'a')
		option[a] = true;
	else if (avc == 'l')
		option[l] = true;
	else if (avc == 'r')
		option[r] = true;
	else if (avc == 't')
		option[t] = true;
	else if (avc == '1')
		option[un] = true;
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(avc, 2);
		ft_putstr_fd("\n", 2);
		ft_putendl_fd("usage : ft_ls [-Raltr1] [file ...]", 2);
		return (-1);
	}
	return (1);
}

int			ft_run_option(int i, char *av, bool *option)
{
	int j;

	j = 1;
	if (av[0] != '-')
		return (0);
	while (av[j])
	{
		if ((ft_filloption(av[j], option) < 0))
			return (-1);
		j++;
	}
	return (1);
}

void		ft_padding_mfile(int t, char **av, int i)
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

int			ft_parsing(char **av, int ac, t_env *env)
{
	int i;
	int j;
	int t;

	i = 0;
	t = 0;
	while (++i < ac)
	{
		j = ft_run_option(i, av[i], env->option);
		if (j == -1)
			exit(EXIT_FAILURE);
		else if (j == 0)
		{
			while ((++i - 1) < ac)
			{
				ft_padding_mfile(++t, av, i);
				if (ft_strchr(av[i - 1], 47) == NULL)
					make_ls(ft_strcat_path(".", av[i - 1]), env);
				else
					make_ls(av[i - 1], env);
			}
			return (0);
		}
	}
	if (j == 1)
	{
		if (av[i - 1][0] == '-')
		{
			make_ls(".", env);
		}
		else
		{
			make_ls(ft_strcat_path(".", av[i - 1]), env);
		}
	}
	return (0);
}
