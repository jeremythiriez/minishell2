/*
** my_exit.c for my_exit.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Sep  1 13:08:48 2016 jeremy thiriez
** Last update Tue Sep  6 11:03:21 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		my_exit(t_ms *ms, char **cmd)
{
  if (cmd[1] && (cmd[2] != NULL ||
		     (cmd[1][0] > '9' || cmd[1][0] < '0')))
    my_puterr("exit: Expression Syntax.\n");
  else if (cmd[1] && my_getnbr(cmd[1]) == EXIT_FAILURE)
    my_puterr("exit: Badly formed number.\n");
  else
    {
      free_tab(ms->all_path);
      free_tab(ms->env);
      my_putstr("exit\n");
      exit(0);
    }
  return (EXIT_SUCCESS);
}
