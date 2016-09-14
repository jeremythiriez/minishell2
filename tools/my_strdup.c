/*
** my_strdup.c for my_strdup.c in /home/thirie_a/rendu/Piscine_C_J08/ex_01
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Wed Mar  9 10:17:11 2016 jeremy thiriez
** Last update Sun Aug 28 22:20:10 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
