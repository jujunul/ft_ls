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

typedef struct  s_mem
{
  struct dirent *dp;
  struct s_mem  *content;
  struct s_mem  *prev;
  struct s_mem  *next;
  char          *patt;
  struct stat   info;
}               t_mem;

typedef struct	s_env
{
  struct s_mem *first;
  struct s_mem *mem;
  char          **path;
  DIR 					*dir;
  char          option[6];
  char				pwd[64];
  size_t				pwdlen;
  char				grp[64];
  size_t				grplen;
}								t_env;

#endif
