/*
** err_lexer.c for err_lexer.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/lexer
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Mon Sep  5 10:41:23 2016 jeremy thiriez
** Last update Sun Sep 11 20:17:39 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		multi_redi(t_lexer *lexer, t_ms *ms)
{
  t_lexer	*tmp;
  int		redi[2];

  redi[0] = 0;
  redi[1] = 0;
  tmp = lexer->next;
  while (tmp->next)
    {
      if (tmp->type == PIPE || tmp->type == DOT_COMA)
	{
	  redi[1] = 0;
	  redi[0] = 0;
	}
      if (tmp->data[0][0] == '<')
	redi[0] += 1;
      if (tmp->data[0][0] == '>')
	redi[1] += 1;
      if (redi[0] > 1 || redi[1] > 1)
	{
	  ambi_out(ms);
	  return (EXIT_FAILURE);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int		check_pars_inv(t_lexer *tmp)
{
  if (((def_in_ope(tmp->data[0], 0) == 1) &&
       tmp->next->data[0] == NULL)  ||
      (def_in_ope(tmp->data[0], 0) == 1 &&
       def_in_ope(tmp->next->data[0], 0) == 1))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		err_lexer_redi(t_lexer *lexer, t_ms *ms)
{
  t_lexer	*tmp;

  tmp = lexer->next;
  while (tmp->next)
    {
      if ((tmp->type == 5 && tmp->next->type == 5) ||
	  (tmp->type == 5 && tmp->next->type == 1))
	{
	  err_redi(ms);
	  return (EXIT_FAILURE);
	}
      if (tmp->type == 4 && tmp->next->type == 1)
	{
	  ambi_out(ms);
	  return (EXIT_FAILURE);
	}
      else if (check_pars_inv(tmp) == EXIT_FAILURE)
	{
	  pars_inv(ms);
	  return (EXIT_FAILURE);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int		err_double_ope(t_lexer *lexer, t_ms *ms)
{
  t_lexer	*tmp;

  tmp = lexer;
  if (tmp->next->type == 4 ||
      tmp->next->type == 5)
    {
      pars_inv(ms);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		err_lexer(t_lexer *lexer, t_ms *ms)
{
  if (((err_double_ope(lexer, ms) == EXIT_FAILURE ||
      (err_lexer_redi(lexer, ms) == EXIT_FAILURE)) ||
      (multi_redi(lexer, ms) == EXIT_FAILURE)) ||
      (add_color_ls(lexer) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
