/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:48:14 by juthierr          #+#    #+#             */
/*   Updated: 2017/07/09 01:25:14 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <grp.h>
# include <pwd.h>
# include <unistd.h>
# include <sys/stat.h>
#include <stdio.h>
# include "libft.h"
typedef int bool;
# define false 0
# define true 1

enum
{
  r,
  a,
  l,
  R,
  t
};


typedef struct  s_mem
{
  char          *name;
  struct s_mem  *next;
  struct s_mem  *dir;
}               t_mem;

typedef struct	s_env
{
  bool          option[5];
  char          **path;
}								t_env;

/*
parsing argument
*/
int       ft_parsing(char **av, int ac, t_env *env);
int       ft_run_option(int i, char *av, bool *option);
int       ft_filloption(char avc, bool *option);
void      ft_init_arg(bool *option);

/*
make_ls
*/
void    make_ls(char *path, t_env *env);
t_mem     *ft_lst_sort(t_mem *lst, struct dirent *dp);
t_mem    *ft_mem(t_mem *lst, struct dirent *dp, t_env *env);
void    ft_affichage(t_mem *lst, t_env *env);
char    *ft_strcat_path(char *s1, char *s2);
t_mem* ft_lst_sort_r(t_mem *lst, struct dirent *dp);

#endif
