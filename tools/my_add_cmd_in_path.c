/*
** my_add_cmd_in_path.c for my_add_cmd_in_path.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 19:22:46 2016 jeremy thiriez
** Last update Tue Aug 30 19:22:55 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char	*my_add_cmd_in_path(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i])
      i = i + 1;
  dest[i] = '/';
  i++;
  while (src[j])
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
