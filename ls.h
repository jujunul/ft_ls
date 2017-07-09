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
# include "libft.h"

typedef struct	s_env
{
	int recur;
	int hidden;

}				t_env;

#endif
