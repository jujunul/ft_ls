/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:47:31 by juthierr          #+#    #+#             */
/*   Updated: 2017/06/22 16:42:06 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int ac, char **av)
{
	//gerer dans lordre -atrRl
	//regarder ls -1
	DIR *dir;
	struct dirent *dp;
	char *file_name;
	dir = opendir(av[1]);
	while ((dp = readdir(dir)) != NULL)
	{
		printf("%s\n", dp->d_name);
	}
	closedir(dir);
	return (0);
}
