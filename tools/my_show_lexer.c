/*
** my_show_lexer.c for my_shor_lexer.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 18:14:07 2016 jeremy thiriez
** Last update Sun Sep 11 19:29:00 2016 jeremy thiriez
*/

#include "mysh.h"

void		my_show_lexer(t_lexer *lexer)
{
  t_lexer	*tmp;

  tmp = lexer;
  while (tmp)
    {
      my_show_wordtab(tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
