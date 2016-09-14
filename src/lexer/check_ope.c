/*
** check_epo.c for check_ope.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/lexer
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 23:32:39 2016 jeremy thiriez
** Last update Wed Aug 31 21:38:53 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		check_ope(char *ope)
{
  if (ope[0] == '<' || ope[0] == '>' ||
      ope[0] == '|' || ope[0] == '&')
    {
      if (my_strlen(ope) > 2)
	{
	  my_puterr(PARS_INV);
	  return (EXIT_FAILURE);
	}
      else
	return (2);
    }
  else if (ope[0] == ';')
    {
      if (my_strlen(ope) > 1)
	{
	  my_puterr(PARS_INV);
	  return (EXIT_FAILURE);
	}
      else
	return (2);
    }
  return (EXIT_SUCCESS);
}
