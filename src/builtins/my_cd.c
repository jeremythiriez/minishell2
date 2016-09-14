/*
** my_cd.c for my_cd.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Sep  1 12:43:33 2016 jeremy thiriez
** Last update Sun Sep 11 19:29:57 2016 jeremy thiriez
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "mysh.h"

int		my_choose_cd(char **cd, t_ms *ms)
{
  struct stat	st;

  stat(cd[1], &st);
  if (S_ISDIR(st.st_mode) == 1)
    {
      if (set_pwd(ms, "OLDPWD=") == EXIT_FAILURE)
	return (EXIT_FAILURE);
      chdir(cd[1]);
    }
  else if (S_ISREG(st.st_mode) == 1)
    {
      my_puterr(cd[1]);
      my_puterr(NO_DIR);
      ms->ret_val = 1;
    }
  else
    {
      my_puterr(cd[1]);
      my_puterr(NO_S_D);
      ms->ret_val = 1;
    }
  return (EXIT_SUCCESS);
}

int		my_cd_err(char **tab)
{
  if (my_len_tab(tab) > 2)
    {
      my_puterr("cd: ");
      my_puterr(TOO_MANY_ARG);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		my_cd(char **cd, t_ms *ms)
{
  if (my_cd_err(cd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (cd[1] == NULL || cd[1][0] == '~')
    chdir(my_getenv(ms->env, "HOME="));
  else if (cd[1][0] == '-')
    {
      chdir(my_getenv(ms->env, "OLDPWD="));
      if (swap_pwd(ms) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    if (my_choose_cd(cd, ms) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
