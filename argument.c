/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lala.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:33:54 by juthierr          #+#    #+#             */
/*   Updated: 2017/08/07 17:33:56 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void ft_init_arg(bool   *option)
{
  option[R] = false;
  option[a] = false;
  option[l] = false;
  option[r] = false;
  option[t] = false;
}

int    ft_filloption(char *avc, t_env *env)
{
  int i;
  i = 1
  while (avc[i])
  {
    if (avc[i] == 'R')
      env->option[R] = true;
    else if (avc[i] == 'a')
      env->option[a] = true;
    else if (avc[i] == 'l')
      env->option[l] = true;
    else if (avc[i] == 'r')
      env->option[r] = true;
    else if (avc[i] == 't')
      env->option[t] = true;
    else
    {
      ft_puterror("option non gerer");
      exit;
    }
  }
}
int    ft_run_option(int i, char **av,  t_env*env)
{
  int j;

  j = 0;
  while (av[i][j])
  {
    if (av[i][j] == '-')
    {
      if(!(ft_filloption(av[i], env)))
      //ft_print error option;
        return (0);
    }
  }

}
int     ft_parsing(int ac, char **av, t_env *env)
{
  int i;

  i = 1;
  ft_init_arg(env->option);
  while (i <= ac)
  {
    ft_run_option(i, av, env);
    i++;
  }
  return (1)
}

int     main(int ac, char **av)
{

  t_env   *env;

  env = (t_env *)malloc(sizeof(t_env));
  ft_parsing(ac, av, env);
  printf("%d\n", env->option[R]);
  return (0);
}
