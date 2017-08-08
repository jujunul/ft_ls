/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:45:36 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/08 20:45:38 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ls.h"

void		ft_mem(t_mem *lst, struct dirent *dp)
{
	t_mem	*tmp;
	if (lst->name == NULL)
	{
		lst->name = ft_strdup(dp->d_name);
	}
	else
	{
		//TRIIIIE A FAIRE DANS CETTE CONDITION DE BOUCLE POUR L'ORDRE HHAHAHAHAHHAHAHAHAHHAHAHAA!!!!!!!
		while(lst->next != NULL)
			lst = lst->next;
		tmp = (t_mem *)malloc(sizeof(t_mem));
		if(!(tmp->name = ft_strdup(dp->d_name)))
		{
			ft_putendl_fd("malloc erreur", 2);
			exit (0);
		}
		lst->next = tmp;
	}
}

void		ft_affichage(lst)
{

}
void		make_ls(char *path)
{
	t_mem			*lst;
	struct dirent	*dp;
	DIR				*dir;

	if (!(lst = (t_mem*)malloc(sizeof(t_mem))))
	{
		ft_putendl_fd("malloc error", 2);
		exit (0);
	}
	dir = opendir(path);
	while ((dp = readdir(dir)) != NULL)
	{
		ft_mem(lst, dp);
		//MEM ET TRIE + RECUR AVEC LE DIR JUSTE AU DESSUS
		//FAIRE LES FONCTION AFFICHAGES APRES CA(AUTRE FONCTION) 

		if (lst->namae[0] != '.')
		{
			ft_putstr(ft_strcat(dp->d_name, "\t"));
		}
	}
	closedir(dir);
}