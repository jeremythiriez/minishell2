/*
** my_begin_match.c for my_negin_match.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 18:43:14 2016 jeremy thiriez
** Last update Tue Aug 30 18:48:21 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		my_begin_match(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (EXIT_FAILURE);
  while (s2[i])
    {
      if (s1[i] != s2[i])
	return (EXIT_FAILURE);
      i += 1;
    }
  return (EXIT_SUCCESS);
}
