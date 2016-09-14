/*
** echo.c for echo.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Sep  1 07:57:34 2016 jeremy thiriez
** Last update Thu Sep  1 08:07:37 2016 jeremy thiriez
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int		my_echo(char **tab, int fd)
{
  int		i;
  int		len;

  i = 1;
  len = my_len_tab(tab);
  while (tab[i])
    {
      write(fd, tab[i], my_strlen(tab[i]));
      if (i < len - 1)
	my_putchar(' ');
      i += 1;
    }
  my_putchar('\n');
  return (EXIT_SUCCESS);
}
