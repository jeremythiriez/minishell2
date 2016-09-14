/*
** free_lexer.c for free_lexer.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 22:49:11 2016 jeremy thiriez
** Last update Tue Aug 30 22:56:45 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		free_lexer(t_lexer *lexer)
{
  while (lexer->next)
    {
      lexer = lexer->next;
      free(lexer->prev);
    }
  return (EXIT_SUCCESS);
}
