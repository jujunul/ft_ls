/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 06:56:30 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/18 06:56:32 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	main(int ac , char **av)
{
	t_env *env;
	int i;
	int j;

	i = 1;
	env = (t_env*)malloc(sizeof(t_env));
	ft_init_arg(env->option);
	if (ac == 1)
	{
		make_ls(".", env);
		return (0);
	}
	else
	{
		while (i < ac)
		{
			j = ft_run_option(i, av[i], env->option);
			if (j == -1)
				exit(EXIT_FAILURE);
			else if (j == 0)
			{
				break;
			}
			i++;
		}
	}
	if (j == 0)
	{
		while ((i - 1) < ac)
		{
			make_ls(av[i - 1], env);
			i++;
		}
		return (0);
	}
	else if (j == 1)
	{
		if (av[i - 1][0] == '-')
		{
			make_ls(".", env);
		}
		else
			make_ls(av[i - 1] , env);
	}
}