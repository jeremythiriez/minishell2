/*
** join_string.c for join_string.c in /home/jeremy/rendu/PSU/PSU_2015_minishell1/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Sep  1 03:54:48 2016 jeremy thiriez
** Last update Thu Sep  1 04:16:27 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char		*join_string(char *s1, char *s2)
{
  char		*dest;

  if ((dest = malloc(sizeof(char) *
		     (my_strlen(s1) + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  dest = my_strcpy(s1, dest);
  dest = my_strcat(dest, s2);
  return (dest);
}
