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

t_mem		*ft_lst_sort_r(t_mem *lst, struct dirent *dp)
{
	t_mem *tmp;
	t_mem *prev;
	t_mem *new;

	new = (t_mem*)malloc(sizeof(t_mem));
	tmp = lst;
	prev = NULL;
	new->name = ft_strdup(dp->d_name);
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, dp->d_name) <= 0)
		{
			if (prev == NULL)
			{
				new->next = tmp;
				lst = new;
				break ;
			}
			else
			{
				new->next = tmp;
				prev->next = new;
				break;
			}
		}
		if (tmp->next == NULL)
		{
			tmp->next = new;
			new->next = NULL;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

char *ft_strcat_path(char *s1, char *s2)
{
	char *buf;

	buf = ft_strnew((size_t)(ft_strlen(s1) + ft_strlen(s2) + 1));
	buf = ft_strcat(s1,"/");
	buf = ft_strcat(s1, s2);
	return (buf);
}

int     main(int ac, char **av)
{
	t_env *env;
	int i;

	env = (t_env *)malloc (sizeof(t_env));	
	if (ac == 1)
	{
		ft_init_arg(env->option);
  		make_ls(".", env);
  	}
 	else
	{
		i = ft_parsing(ac, av, env);
		if (i < 0)
			return (0);
		else if (i == ac)
			make_ls(".", env);
		else
		{
			while (i < ac)
			{
				make_ls(ft_strcat(".", av[i]) , env);
				i++;
			}
		}
	}
	return (0);
}
