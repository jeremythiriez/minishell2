/*
** setenv.c for setenv.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Sep  1 05:36:24 2016 jeremy thiriez
** Last update Sun Sep 11 11:50:58 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		setenv_err(char **tab, char **env)
{
  if (my_len_tab(tab) == 1)
    {
      my_show_wordtab(env);
      return (EXIT_FAILURE);
    }
  else if (my_len_tab(tab) > 3)
    {
      my_puterr("setenv: ");
      my_puterr(TOO_MANY_ARG);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

char		**add_var_end(char **env, char **tab, char *tmp)
{
  int		len;

  len = my_len_tab(env);
  if ((env = realloc_tab(env)) == NULL)
    return (NULL);
  if ((env[len] = join_string(tmp, tab[2])) == NULL)
    return (NULL);
  env[len + 1] = 0;
  return (env);
}

char		**my_setenv(char **env, char **tab)
{
  int		i;
  char		*tmp;

  i = 0;
  if (setenv_err(tab, env) == EXIT_FAILURE ||
      (tmp = add_egal(tab[1])) == NULL)
    return (env);
  while (env[i])
    {
      if (my_begin_match(env[i], tmp) == 0)
	{
	  if ((env[i] = join_string(tmp, tab[2])) == NULL)
	    return (env);
	  return (env);
	}
      i += 1;
    }
  if ((env = add_var_end(env, tab, tmp)) == NULL)
    return (env);
  return (env);
}
