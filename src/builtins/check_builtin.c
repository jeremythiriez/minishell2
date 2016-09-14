/*
** check_builtin.c for check_builtins.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Sep  6 09:51:23 2016 jeremy thiriez
** Last update Sun Sep 11 11:51:30 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		check_builtins(char **cmd)
{
  if (my_strcmp(cmd[0], "exit") == 0 ||
      my_strcmp(cmd[0], "setenv") == 0 ||
      my_strcmp(cmd[0], "env") == 0 ||
      my_strcmp(cmd[0], "cd") == 0 ||
      my_strcmp(cmd[0], "unsetenv") == 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		exec_builtins(char **cmd, t_ms *ms)
{
  if (my_strcmp(cmd[0], "exit") == 0)
    my_exit(ms, cmd);
  else if (my_strcmp(cmd[0], "env") == 0)
    {
      if (my_env(cmd, ms) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (my_strcmp(cmd[0], "setenv") == 0)
    {
      if ((ms->env = my_setenv(ms->env, cmd)) == NULL)
	return (EXIT_FAILURE);
    }
  else if (my_strcmp(cmd[0], "unsetenv") == 0)
    {
      if ((ms->env = my_unsetenv(ms->env, cmd)) == NULL)
	return (EXIT_FAILURE);
    }
  else if (my_strcmp(cmd[0], "cd") == 0)
    if (my_cd(cmd, ms) == EXIT_FAILURE)
      return (EXIT_SUCCESS);
  ms->all_path = my_str_to_word_tab(my_getenv(ms->env, PATH));
  return (EXIT_SUCCESS);
}
