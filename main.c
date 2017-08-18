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

	buf = ft_strnew((ft_strlen(s1) + ft_strlen(s2) + 4));
	buf = ft_strcpy(buf, s1);
	buf = ft_strcat(buf,"/");
	buf = ft_strcat(buf, s2);
	return (buf);
}

int	main(int ac , char **av)
{
	t_env *env;
	int i;
	int j;

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