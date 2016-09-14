/*
** free_tab.c for free_tab.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 20:05:01 2016 jeremy thiriez
** Last update Tue Aug 30 20:07:38 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i += 1;
    }
  return (EXIT_SUCCESS);
}
