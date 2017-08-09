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

char *ft_strcat_path(char *s1, char *s2)
{
	char *buf;

	buf = ft_strnew((size_t)(ft_strlen(s1) + ft_strlen(s2) + 1));
	buf = ft_strcat(s1,"/");
	buf = ft_strcat(s1, s2);
	return (buf);
}

void	ft_ls_onall(int ac, char **av, t_env *env)
{
	int i;

	i = 1
	while (av[i])
	{
		make_ls(av[i], env);
		i++;
	}
}

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
		ft_ls_onall(ac, av , env)
		//make_lsall(ac, av, env);
	}
	return (0);
}
