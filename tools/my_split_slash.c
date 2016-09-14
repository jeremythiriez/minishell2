/*
** my_split_word_ope.c for my_split_word_ope.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools/test
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Wed Aug 31 12:48:21 2016 jeremy thiriez
** Last update Sat Sep 10 10:21:23 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		def_in_ope_slash(char *str, int i)
{
  if (str[i] == '&' || str[i] == '|' ||
      str[i] == '<' || str[i] == '>' ||
      str[i] == ';' || str[i] == '/')
    return (1);
  return (0);
}

char		*cpy_ope_slash(char *str, int **i)
{
  char		*dest;
  int		j;
  char		c;

  j = 0;
  if ((dest = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  dest[0] = 0;
  c = str[**i];
  while (str[**i] && j < 2 && str[**i] == c)
    {
      if ((dest = my_realloc(dest, 1)) == NULL)
	return (NULL);
      dest[j] = str[**i];
      dest[j + 1] = 0;
      **i = **i + 1;
      j += 1;
    }
  dest[j] = 0;
  return (dest);
}

char		*cpy_str_slash(char *str, int **i)
{
  char		*dest;
  int		j;

  j = 0;
  if ((dest = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  dest[0] = 0;
  while (str[**i]
	 && str[**i] != ' '
	 && str[**i] != '\t'
	 && def_in_ope_slash(str, **i) == 0)
    {
      if ((dest = my_realloc(dest, 1)) == NULL)
	return (NULL);
      dest[j] = str[**i];
      dest[j + 1] = 0;
      **i = **i + 1;
      j += 1;
    }
  dest[j] = 0;
  return (dest);
}

char		**my_switch_plit_slash(char **dest, char *str, int *i, int *j)
{
  if ((dest = realloc_tab(dest)) == NULL)
    return (NULL);
  if (def_in_ope_slash(str, *i) == 0)
    {
      if ((dest[*j] = cpy_str_slash(str, &i)) == NULL)
	return (NULL);
    }
  else
    if ((dest[*j] = cpy_ope_slash(str, &i)) == NULL)
      return (NULL);
  *j = *j + 1;
  dest[*j] = 0;
  return (dest);
}

char		**my_split_slash(char *str)
{
  char		**dest;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((dest = malloc(sizeof(char *) * 1)) == NULL)
    return (NULL);
  dest[0] = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  if ((dest = my_switch_plit_slash(dest, str, &i, &j)) == NULL)
	    return (NULL);
	}
      else
	i += 1;
    }
  return (dest);
}
