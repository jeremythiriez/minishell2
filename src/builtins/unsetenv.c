/*
** unsetenv.c for  in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Sep  1 06:20:44 2016 jeremy thiriez
** Last update Tue Sep  6 11:41:47 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		unsetenv_err(char **tab)
{
  if (my_len_tab(tab) == 1)
    {
      my_puterr("unsetenv: ");
      my_puterr(TOO_FEW_ARG);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

char		**my_decale_tab(char **env, int i)
{
  while (env[i])
    {
      env[i] = env[i + 1];
      i += 1;
    }
  return (env);
}

char		**my_unsetenv(char **env, char **cmd)
{
  char		*tmp;
  int		i;

  i = 0;

  if ((unsetenv_err(cmd) == EXIT_FAILURE) ||
      (tmp = add_egal(cmd[1])) == NULL)
    return (env);
  while (env[i])
    {
      if (my_begin_match(env[i], tmp) == 0)
	env = my_decale_tab(env, i);
      i += 1;
    }
  return (env);
}
