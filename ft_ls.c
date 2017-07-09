/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:47:31 by juthierr          #+#    #+#             */
/*   Updated: 2017/07/09 01:26:32 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "stdio.h"

int		main(int ac, char **av)
{
	//gerer dans lordre -atrRl
	//regarder ls -1
  ac = 0;
	DIR *dir;
	int test;
	struct dirent *dp;
	struct stat		*info;
	info = malloc(sizeof(struct stat));
	dir = opendir(av[1]);
	while ((dp = readdir(dir)) != NULL)
	{
		printf("%s\n", dp->d_name);
		test = stat(av[1], info);
		printf("%s\n, ")
		//printf("reclen : %i\n", dp->d_reclen);
		//printf("ino : %llu\n", dp->d_ino);
		//printf("namlenght : %i\n", dp->d_namlen);
	}
	closedir(dir);
	return (0);
}
