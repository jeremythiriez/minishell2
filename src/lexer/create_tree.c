/*
** create_tree.c for create_tree.c in /home/jeremy/test/eval_exper/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Thu Sep  1 08:49:01 2016 jeremy thiriez
** Last update Sun Sep 11 19:58:18 2016 jeremy thiriez
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

t_tree		*create_tree_node(t_lexer *token)
{
  t_tree	*node;

  if ((node = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  node->data = my_cpy_tab(node->data, token->data);
  node->type = token->type;
  node->on = true;
  return (node);
}

t_lexer		*find_token(t_lexer *token, t_lexer *tmp, t_lexer *begin)
{
  while (tmp != begin)
    {
      if (tmp->type < token->type)
	token = tmp;
      tmp = tmp->prev;
    }
  return (token);
}

int		make_tree(t_tree *racine, t_lexer *begin, t_lexer *end)
{
  t_lexer	*tmp;
  t_lexer	*token;

  tmp = end;
  token = tmp;
  if (begin == end)
    {
      racine->data = my_cpy_tab(racine->data, token->data);
      racine->type = token->type;
      racine->on = true;
      racine->left = NULL;
      racine->right = NULL;
      return (EXIT_SUCCESS);
    }
  token = find_token(token, tmp, begin);
  racine->data = my_cpy_tab(racine->data, token->data);
  racine->type = token->type;
  racine->on = true;
  if ((((racine->left = malloc(sizeof(t_tree))) == NULL) ||
       (racine->right = malloc(sizeof(t_tree))) == NULL) ||
      (make_tree(racine->left, begin, token->prev)) == EXIT_FAILURE ||
      (make_tree(racine->right, token->next, end)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		create_tree(t_ms *ms)
{
  t_lexer	*end;

  end = ms->lexer;
  if ((ms->tree = malloc(sizeof(t_tree))) == NULL)
    return (EXIT_FAILURE);
  while (end->next->next)
    end = end->next;
  if (make_tree(ms->tree, ms->lexer->next, end) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
