/*
** my_strcat.c for my_strcat.c in /home/thirie_a/rendu/Piscine_C_J07/ex_02
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Mar  8 11:35:28 2016 jeremy thiriez
** Last update Thu Sep  1 04:07:37 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (src != NULL)
    {
      while (dest[i])
	i++;
      while (src[j])
	{
	  dest[i] = src[j];
	  i++;
	  j++;
	}
      dest[i] = 0;
    }
  return (dest);
}
