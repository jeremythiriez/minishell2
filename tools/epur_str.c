/*
** epur_str.c for epur_str.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Wed Aug 31 03:08:09 2016 jeremy thiriez
** Last update Sun Sep 11 21:29:04 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

void		recale_str(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      str[i] = str[i + 1];
      i += 1;
    }
}

char		*epur_str(char *str)
{
  int		i;

  i = 0;
  while (str[0] == ' ' || str[0] == '\t')
    recale_str(str);
  while (str[i])
    {
      while ((str[i] == ' ' || str[i] == '\t') &&
	     (str[i + 1] == ' ' || str[i + 1] == '\t'))
	recale_str(str + i);
      i += 1;
    }
  if (str[0] == 0)
    return (str);
  while (str[my_strlen(str) - 1] == ' ' ||
	 str[my_strlen(str) - 1] == '\t')
    str[my_strlen(str) - 1] = 0;
  return (str);
}
