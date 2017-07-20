/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:59:18 by juthierr          #+#    #+#             */
/*   Updated: 2017/07/20 01:32:09 by juthierr         ###   ########.fr       */
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

void  ft_mem(t_mem *mem, t_mem *dest)
{
	t_mem			*tmp;
	t_mem			*new;

	tmp = mem;
	new = (t_mem*)malloc(sizeof(t_mem));
	while (tmp->next != NULL)
	 tmp = tmp->next;
	if (tmp->name == NULL)
	{
		new->name = ft_strdup(new->dp->d_name);
		new->type = new->dp->d_type;
	}

}

void 	ft_init_mem(t_mem *mem)
{
	mem->path = ft_strdup(".");
	mem->prev = NULL;
	mem->next = NULL;
	mem->content = NULL;
	mem->name = NULL;
	mem->type = NULL;
}

void  ft_read_file(t_mem *mem, t_env *env)
{
	t_mem		*tmp;

	tmp = mem;
	mem->dir = opendir(mem->path);
	while ((mem->dp = readdir(mem->dir)) != NULL)
	{
		ft_mem(mem, );
		mem = mem->next;
	}
	while(tmp->next != NULL) /* option -R*/
	{
		if(tmp->type == S_ISDIR)
		{
			tmp->path = ft_strcat_path(tmp->path, tmp->name);
			ft_read_file(tmp->content, env);
		}
	}
}

int		main(int ac, char **av)
{
	t_mem					*mem;

	mem = (t_mem*)malloc(sizeof(t_mem));
	if (ac == 1)
	{
		ft_init_mem(mem);
		ft_read(mem);

	}
}
