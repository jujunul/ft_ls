/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:29:57 by juthierr          #+#    #+#             */
/*   Updated: 2017/07/09 01:24:50 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int ac, char **av)
{
	t_env *option;
	//init option
	//
	if (ac >= 2)
	{
		if (av[1][0] != '-')
		{
			if (ft_ls(ac, av, 1, option) == 0)
			{
				ft_print_erno();
				printf("pas d'argument, wrong path\n")
					return (0);
			}
			printf("pas d'argument/ path direct\n");
		}
		if (av[1][0] == '-')
		{
			ft_ls(ac, av, 0, option);
			printf("ls avec option");
		}
	}
	else
		printf("ls no option, current path");
	return (0);
}
