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

char	*ft_strcat_path(char *s1, char *s2)
{
	char *buf;

	buf = ft_strnew((ft_strlen(s1) + ft_strlen(s2) + 4));
	buf = ft_strcpy(buf, s1);
	buf = ft_strcat(buf, "/");
	buf = ft_strcat(buf, s2);
	return (buf);
}

void	ft_test(t_mem *lst)
{
	while (lst)
	{
		printf("%s\n", lst->name);
		lst = lst->next;
	}
}

int		main(int ac, char **av)
{
	t_env	*env;
	int		i;

	i = 0;
	env = (t_env*)malloc(sizeof(t_env));
	ft_init_arg(env->option);
	if (ac == 1)
	{
		make_ls(".", env);
		return (0);
	}
	else
	{
		ft_parsing(av, ac, env);
		return (0);
	}
}
