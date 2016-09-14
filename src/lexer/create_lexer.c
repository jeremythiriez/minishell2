/*
** create_lexer.c for create_lexer.c in /home/jeremy/rendu/PSU/PSU_2015_tetris/src/debug_mode
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Mon Jul 25 15:42:20 2016 jeremy thiriez
** Last update Sun Sep 11 13:51:43 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

t_lexer		*create_node(char *data, int type)
{
  t_lexer	*node;

  if ((node = malloc(sizeof(t_lexer))) == NULL)
    return (NULL);
  if ((node->data = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  node->data[0] = data;
  node->data[1] = 0;
  node->type = type;
  node->next = NULL;
  node->prev = NULL;
  return (node);
}

int		add_flag(char *flag, t_lexer *tmp, int *j)
{
  while (tmp->next)
    tmp = tmp->next;
  if ((tmp->data = realloc_tab(tmp->data)) == NULL)
    return (EXIT_FAILURE);
  tmp->data[*j] = flag;
  tmp->data[*j + 1] = 0;
  *j = *j + 1;
  return (EXIT_SUCCESS);
}

int		add_node(t_lexer *tmp, int i, char **av, int type)
{
  t_lexer	*node;

  if ((node = create_node(av[i], type)) == NULL)
    return (EXIT_FAILURE);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = node;
  node->prev = tmp;
  return (EXIT_SUCCESS);
}

int		add_end_node(t_lexer *tmp, int type)
{
  t_lexer	*node;

  if ((node = create_node(NULL, type)) == NULL)
    return (EXIT_FAILURE);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = node;
  node->prev = tmp;
  return (EXIT_SUCCESS);
}

t_lexer		*create_lexer(char **av)
{
  int		i;
  int		j;
  t_lexer	*lexer;
  t_lexer	*tmp;

  i = -1;
  j = 1;
  if ((lexer = create_node(NULL, BEGIN)) == NULL)
    return (NULL);
  tmp = lexer;
  while (av[++i])
    {
      if (i == 0 || def_in_ope(av[i], 0) == 1 || def_in_ope(av[i - 1], 0) == 1
	  || av[i][0] == '-')
	{
	  j = 1;
	  if (add_node(tmp, i, av, 2) == EXIT_FAILURE)
	    return (NULL);
	}
      else
	if (add_flag(av[i], tmp, &j) == EXIT_FAILURE)
	  return (NULL);
    }
  add_end_node(tmp, END);
  return (lexer);
}
