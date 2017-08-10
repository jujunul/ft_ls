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
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(avc, 2);
		ft_putstr_fd("\n", 2);
		ft_putendl_fd("usage : ft_ls [-Raltr] [file ...]", 2);
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

int			ft_parsing(int ac, char **av, t_env *env)
{
	int i;

	i = 1;
	ft_init_arg(env->option);
	while (i < ac)
	{
		if (ft_run_option(i, av[i], env->option) < 0)
			return (-1);
		i++;
	}
	return (i);
}
