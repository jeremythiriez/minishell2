/*
** modif_lexer.c for modif_lexer.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/lexer
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Wed Aug 31 00:44:11 2016 jeremy thiriez
** Last update Sun Sep 11 13:57:43 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		replace_flag(t_lexer *tmp, t_lexer *tmp2)
{
  int		i;
  int		j;

  j = 0;
  if (tmp->data[0][0] == '-')
    {
      while (tmp->data[j])
	{
	  i = my_len_tab(tmp2->data);
	  if ((tmp2->data = realloc_tab(tmp2->data)) == NULL)
	    return (EXIT_FAILURE);
	  tmp2->data[i] = tmp->data[j];
	  tmp2->data[i + 1] = 0;
	  j += 1;
	}
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
    }
  return (EXIT_SUCCESS);
}

int		modif_lexer(t_lexer *lexer)
{
  t_lexer	*tmp;
  t_lexer	*tmp2;

  tmp = lexer->next;
  while (tmp)
    {
      tmp2 = tmp;
      while (tmp->next
	     && tmp->data[0][0] != '|'
	     && tmp->data[0][0] != ';'
	     && tmp->data[0][0] != '&')
	{
	  if (replace_flag(tmp, tmp2) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  tmp = tmp->next;
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

void		redi_point(t_lexer *tmp[6])
{
  tmp[1]->next = tmp[5];
  tmp[5]->prev = tmp[1];
  tmp[4]->next = tmp[2];
  tmp[2]->prev = tmp[4];
  tmp[3]->next = tmp[0];
  tmp[0]->prev = tmp[3];
}

int		check_redi(t_lexer *lexer)
{
  t_lexer	*tmp;

  tmp = lexer;
  while (tmp && tmp->data[0] != NULL &&
	 tmp->data[0][0] != '|' &&
	 tmp->data[0][0] != ';' &&
	 tmp->data[0][0] != '&')
    {
      if (tmp->data[0][0] == '<')
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		swap_redi(t_lexer *lexer)
{
  t_lexer	*tmp[6];

  tmp[0] = lexer->next;
  while (tmp[0])
    {
      if (tmp[0]->data[0] != NULL && tmp[0]->data[0][0] == '>'
	   && check_redi(tmp[0]) == 1)
	{
	  tmp[1] = tmp[0]->prev;
	  tmp[2] = tmp[1]->next;
	  while (tmp[0]->next && tmp[0]->data[0][0] != '<')
	    tmp[0] = tmp[0]->next;
	  tmp[3] = tmp[0]->prev;
	  tmp[4] = tmp[0]->next;
	  tmp[5] = tmp[0];
	  while (tmp[0]->next && tmp[0]->data[0][0] != '|' &&
		 tmp[0]->data[0][0] != ';' && tmp[0]->data[0][0] != '&')
	    tmp[0] = tmp[0]->next;
	  redi_point(tmp);
	}
      tmp[0] = tmp[0]->next;
    }
  return (EXIT_SUCCESS);
}
