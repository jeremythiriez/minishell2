/*
** my_cpy_tab.c for my_cpy_tab.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 19:48:24 2016 jeremy thiriez
** Last update Tue Aug 30 19:56:28 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char		**my_cpy_tab(char **dest, char **src)
{
  int		i;

  i = 0;
  if ((dest = malloc(sizeof(char *) * (my_len_tab(src) + 1))) == NULL)
    return (NULL);
  while (src[i])
    {
      if ((dest[i] = my_strdup(src[i])) == NULL)
	return (NULL);
      i += 1;
    }
  dest[i] = 0;
  return (dest);
}
