/*
** my_env.c for my_env.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Sep  6 11:26:38 2016 jeremy thiriez
** Last update Tue Sep  6 11:36:10 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		env_err(char **cmd)
{
  if (my_len_tab(cmd) > 1)
    {
      my_puterr("env: «");
      my_puterr(cmd[1]);
      my_puterr(ERR_ENV);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		my_env(char **cmd, t_ms *ms)
{
  if (env_err(cmd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  my_show_wordtab(ms->env);
  return (EXIT_SUCCESS);
}
