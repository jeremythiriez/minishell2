/*
** my_str_to_word_tab.c for my_str_to_word_tab.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_minishell1
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Mon Jun 13 21:07:23 2016 jeremy thiriez
** Last update Sun Sep 11 07:35:42 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char		*my_cpy(char *s1, char *s2, int *index)
{
  int		i;

  i = 0;
  if (s1 != NULL)
    while (s1[*index] && s1[*index] != ':' && s1[*index] != ' ')
      {
	s2[i] = s1[*index];
	i++;
	*index = *index + 1;
      }
  s2[i] = 0;
  return (s2);
}

int		count_word(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 1;
  while (str[i])
    {
      if (str[i] == ':' || str[i] == ' ')
	j++;
      i++;
    }
  return (j);
}

int		count_size_word(char *str, int *index)
{
  int		j;

  j = 0;
  while (str[*index] && str[*index] != ':' && str[*index] != ' ')
    {
      *index = *index + 1;
      j++;
    }
  *index = *index + 1;
  return (j);
}

char		**my_malloc_tab(char *str, char **tab, int *index)
{
  int		i;
  int		nb_word;

  i = 0;
  nb_word = count_word(str);
  if ((tab = malloc(sizeof(char *) * (nb_word + 1))) == NULL)
    return (NULL);
  while (i < nb_word)
    {
      if ((tab[i] = malloc(sizeof(char) *
			   (count_size_word(str, index) + 1))) == NULL)
	return (NULL);
      i++;
    }
  return (tab);
}

char		**my_str_to_word_tab(char *str)
{
  char		**tab;
  int		i;
  int		nb_word;
  int		index;

  i = 0;
  index = 0;
  tab = NULL;
  if (str == NULL)
    return (NULL);
  nb_word = count_word(str);
  if ((tab = my_malloc_tab(str, tab, &index)) == NULL)
    return (NULL);
  index = 0;
  while (i < nb_word)
    {
      tab[i] = my_cpy(str, tab[i], &index);
      index++;
      i++;
    }
  tab[i] = 0;
  return (tab);
}
