/*
** add_egal.c for add_egal.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/builtins
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Sep  1 05:30:20 2016 jeremy thiriez
** Last update Thu Sep  1 05:35:38 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char		*add_egal(char *str)
{
  char		*dest;
  int		len;

  len = my_strlen(str);
  if ((dest = malloc(sizeof(char) * (len + 2))) == NULL)
    return (NULL);
  dest = my_strcpy(str, dest);
  dest[len] = '=';
  dest[len + 1] = 0;
  return (dest);
}
