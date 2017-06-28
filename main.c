/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:29:57 by juthierr          #+#    #+#             */
/*   Updated: 2017/06/28 15:14:54 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int ac, char **av)
{
	t_env *options;

	if (ac ==  1 || av[1] == NULL)
	{
		ft_ls(av , 0);
		printf("ls no option juste ls")
	}
	if (av[1][0] != '-')
	{
		if (ft_ls(av, 1) == 0)
		{
			ft_print_erno();
			printf("pas d'argument, wrong path\n")
			return (0);
		}
		printf("pas d'argument/ path direct\n");
	}
	if (ac == 2 && )


}
