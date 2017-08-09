/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 18:15:59 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/08 18:16:02 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int     main(int ac, char **av)
{
	t_env *env;

	env = (t_env *)malloc (sizeof(t_env));
	if (ac == 1)
	{
		ft_init_arg(env->option);
  		make_ls(".", env);
  	}
 	else
	{
		if ((ft_parsing(ac, av, env) < 0))
			return (0);
		//make_lsall(ac, av, env);
	}
	return (0);
}
