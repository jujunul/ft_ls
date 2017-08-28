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

void		ft_init_arg(t_bool *option)
{
	option[R] = FALSE;
	option[a] = FALSE;
	option[l] = FALSE;
	option[r] = FALSE;
	option[t] = FALSE;
	option[un] = FALSE;
}

int			ft_filloption(char avc, t_bool *option)
{
	if (avc == 'R')
		option[R] = TRUE;
	else if (avc == 'a')
		option[a] = TRUE;
	else if (avc == 'l')
		option[l] = TRUE;
	else if (avc == 'r')
		option[r] = TRUE;
	else if (avc == 't')
		option[t] = TRUE;
	else if (avc == '1')
		option[un] = TRUE;
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

int			ft_run_option(char *av, t_bool *option)
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

void		ft_endparse(int j, int i, char **av, t_env *env)
{
	if (j == 1)
	{
		if (av[i - 1][0] == '-')
			make_ls(".", env);
		else
			make_ls(ft_strcat_path(".", av[i - 1]), env);
	}
}

void		ft_parsing(char **av, int ac, t_env *env)
{
	int i;
	int j;
	int t;

	i = 0;
	t = 0;
	while (++i < ac)
	{
		j = ft_run_option(av[i], env->option);
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
			return ;
		}
	}
	ft_endparse(j, i, av, env);
}
