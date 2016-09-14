/*
** my_putstr.c for my_putstr.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_minishell1/tools
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Mon Jun 13 19:11:02 2016 jeremy thiriez
** Last update Wed Aug 31 14:19:23 2016 jeremy thiriez
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int	my_puterr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i])
      {
	write(2, &str[i], 1);
	i++;
      }
  return (EXIT_SUCCESS);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i])
      {
	my_putchar(str[i]);
	i++;
      }
  return (EXIT_SUCCESS);
}
