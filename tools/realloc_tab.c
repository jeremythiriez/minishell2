/*
** realloc_tab.c for my_realloc_tab.c in /home/thirie_a/maxi_save/tech_1/Prog_System_Unix/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sun Aug 28 22:07:56 2016 jeremy thiriez
** Last update Mon Sep  5 09:49:02 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char		**realloc_tab(char **tab)
{
  char		**dest;
  int		i;

  i = 0;
  if ((dest = malloc(sizeof(char *) * (my_len_tab(tab) + 2))) == NULL)
    return (NULL);
  while (tab[i])
    {
      if ((dest[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      i += 1;
    }
  free_tab(tab);
  return (dest);
}
