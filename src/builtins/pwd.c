/*
** pwd.c for pwd.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Sep  6 15:37:27 2016 jeremy thiriez
** Last update Sun Sep 11 00:54:57 2016 jeremy thiriez
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int		swap_pwd(t_ms *ms)
{
  int		j;
  int		k;
  int		i;
  char		*tmp_pwd;

  i = 0;
  while (ms->env[i])
    {
      if (my_begin_match(ms->env[i], "PWD=") == 0)
	j = i;
      if (my_begin_match(ms->env[i], "OLDPWD=") == 0)
	k = i;
      i += 1;
    }
  if (((tmp_pwd = my_strdup(ms->env[j])) == NULL) ||
      (ms->env[j] = malloc(sizeof(char) * (my_strlen(ms->env[k])))) == NULL)
    return (EXIT_FAILURE);
  ms->env[j] = my_strcpy("PWD=", ms->env[j]);
  my_strcat(ms->env[j], ms->env[k] + 7);
  if ((ms->env[k] = malloc(sizeof(char) * (my_strlen(tmp_pwd) + 4))) == NULL)
    return (EXIT_FAILURE);
  ms->env[k] = my_strcpy("OLDPWD=", ms->env[k]);
  my_strcat(ms->env[k], tmp_pwd + 4);
  return (EXIT_SUCCESS);
}

int		set_pwd(t_ms *ms, char *pwd)
{
  char		*old_pwd;
  int		i;

  i = 0;
  if ((old_pwd = malloc(sizeof(char) *
			(my_strlen(ms->pwd) + my_strlen(pwd) + 1))) == NULL)
    return (EXIT_FAILURE);
  old_pwd = my_strcpy(pwd, old_pwd);
  my_strcat(old_pwd, ms->pwd);
  while (ms->env[i])
    {
      if (my_begin_match(ms->env[i], pwd) == 0)
	ms->env[i] = old_pwd;
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int		find_pwd(t_ms *ms)
{
  char		buff[4096];

  if (getcwd(buff, 4096) == NULL)
    return (EXIT_FAILURE);
  if ((((ms->pwd = my_strdup(buff)) == NULL) ||
       (ms->cut_pwd = my_split_slash(ms->pwd)) == NULL) ||
      (set_pwd(ms, "PWD=") == EXIT_FAILURE))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
