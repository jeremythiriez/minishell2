/*
** my_strcmp.c for my_strcmp.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 17:28:01 2016 jeremy thiriez
** Last update Tue Aug 30 17:42:40 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (s1 == NULL)
    return (-1);
  else if (s2 == NULL)
    return (1);
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i += 1;
  return (s1[i] - s2[i]);
}
