/*
** my_put_nbr.c for my_put_nbr.c in /home/thirie_a/rendu/Piscine_C_J03
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu Mar  3 12:05:45 2016 jeremy thiriez
** Last update Tue Aug 30 20:29:26 2016 jeremy thiriez
*/

#include "mysh.h"

int	my_put_nbr(int nb)
{
  char *s1;

  s1 = "-2147483648";
  if (nb == -2147483648)
    my_putstr(s1);
  if ((nb >= -2147483647) && (nb <= 2147483647))
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = nb * (-1);
	}
      if ((nb >= 0) && (nb <= 9))
	my_putchar(nb + 48);
      if (nb > 9)
	{
	  my_put_nbr(nb / 10);
	  my_put_nbr(nb % 10);
	}
    }
  return (0);
}
