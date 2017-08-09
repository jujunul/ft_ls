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
# include <unistd.h>
# include <sys/stat.h>
# include "libft.h"
typedef int bool;
# define false 0
# define true 1

enum
{
  R,
  a,
  l,
  r,
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
int       ft_parsing(int ac, char **av, t_env *env);
int       ft_run_option(int i, char *av, bool *option);
int       ft_filloption(char avc, bool *option);
void      ft_init_arg(bool *option);

/*
make_ls
*/
void    make_ls(char *path);

#endif
