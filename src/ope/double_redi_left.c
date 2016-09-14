/*
** double_redi_left.c for double_redi_left.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/ope
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Sep  6 17:53:27 2016 jeremy thiriez
** Last update Tue Sep  6 18:08:20 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		double_redi_left(char *cmd)
{
  char		*heredoc;

  heredoc = NULL;
  while (my_strcmp(heredoc, cmd) != 0)
    {
      my_putstr("? ");
      if ((heredoc = get_next_line(0)) == NULL)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
