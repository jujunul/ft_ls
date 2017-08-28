/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:48:14 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/24 19:03:55 by juthierr         ###   ########.fr       */
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
# include <stdio.h>
# include <time.h>
# include "libft.h"

typedef int			t_bool;
# define FALSE 		0
# define TRUE 		1

enum
{
	r,
	a,
	l,
	R,
	t,
	un,
};

typedef struct		s_mem
{
	char			*name;
	struct s_mem	*next;
	struct s_mem	*dir;
}					t_mem;

typedef struct		s_env
{
	t_bool			option[6];
	struct stat		buf;
	DIR				*dir;
}					t_env;

void				ft_parsing(char **av, int ac, t_env *env);
int					ft_run_option(char *av, t_bool *option);
int					ft_filloption(char avc, t_bool *option);
void				ft_init_arg(t_bool *option);

void				make_ls(char *path, t_env *env);
t_mem				*ft_mem(t_mem *lst, struct dirent *dp, t_env *env);
char				*ft_strcat_path(char *s1, char *s2);
int					ft_error_directory(char *path, t_env *env);
void				ft_free_list(t_mem *lst);

t_mem				*ft_lst_sort(t_mem *lst, struct dirent *dp);
t_mem				*ft_lst_sort_r(t_mem *lst, struct dirent *dp);
t_mem				*ft_sort_time(t_mem *lst, struct dirent *dp);
t_mem				*ft_sort_time_r(t_mem *lst, struct dirent *dp);
void				ft_simpletest(t_mem *tmp, t_mem *new);
void				ft_free_list(t_mem *lst);
int					ft_isfile(char *path);

void				aff_opt_l(t_mem *lst, t_env *env, char *path);
void				ft_print_permission(struct stat buf);
void				ft_affichage(t_mem *lst, t_env *env, char *path);
void				ft_print_uid(struct stat buf);
void				ft_print_gid(struct stat buf);
void				ft_aff_on_file(char *path, t_env *env);
void				ft_printotal(int total);
void				ft_putname(char *name, char *path, struct stat buf);
void				ft_printonlyyear(t_mem *lst, char *path);
void				ft_printonlymin(t_mem *lst, char *path);
void				ft_puttime(t_mem *lst, char *path);
void				ft_aff_all(struct stat buf, t_mem *lst, char *path);
void				ft_padding_mfile(int t, char **av, int i);
void				ft_get_total(t_mem *lst, char *path, t_env *env);
void				ft_printnamefile(char *path);

#endif
