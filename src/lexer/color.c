/*
** color.c for color.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/bonus/src/lexer
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Sun Sep 11 20:12:01 2016 jeremy thiriez
** Last update Sun Sep 11 20:15:28 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		add_color_ls(t_lexer *lexer)
{
  t_lexer	*tmp;
  int		i;

  tmp = lexer->next;
  while (tmp->next)
    {
      if (my_strcmp(tmp->data[0], "ls") == 0)
	{
	  i = my_len_tab(tmp->data);
	  if ((tmp->data = realloc_tab(tmp->data)) == NULL)
	    return (EXIT_FAILURE);
	  tmp->data[i] = "--color";
	  tmp->data[i + 1] = 0;
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
