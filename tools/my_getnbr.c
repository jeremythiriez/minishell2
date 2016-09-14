/*
** my_getnbr.c for my_getnbr.c in /home/thirie_a/rendu/Piscine_C_J04
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Fri Mar  4 12:20:12 2016 jeremy thiriez
** Last update Fri Jun 24 18:18:54 2016 Live session user
*/

#include <stdlib.h>
#include "mysh.h"

void	my_check(char *str, int *i, int *j)
{
  while (str[*i] == '+' || str[*i] == '-')
    {
      if (str[*i] == '-')
	*j = *j + 1;
      *i = *i + 1;
    }
}

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  long	result;

  i = 0;
  result = 0;
  j = 0;
  my_check(str, &i, &j);
  while (str[i])
    {
      result = (result * 10) + (str[i] - 48);
      if ((result > 2147483647 && !(j % 2 == 1)) ||
	  (result > 2147483648 && (j % 2 == 1)))
	return (0);
      if (str[i] > '9' || str[i] < '0')
	return (EXIT_FAILURE);
      i = i + 1;
    }
  if (j % 2 == 1)
    result = result * -1;
  return (result);
}
