/*
** create_list.c for create_list.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_minishell1/src
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Jun 14 23:26:34 2016 jeremy thiriez
** Last update Tue Aug 30 18:36:04 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

t_list		*create_node_list(char *data)
{
  t_list	*node;

  if ((node = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  node->data = my_strdup(data);
  node->next = NULL;
  node->prev = NULL;
  return (node);
}

t_list		*add_elem(t_list *list, char *elem)
{
  t_list	*tmp;
  t_list	*node;

  tmp = list;
  if ((node = create_node_list(elem)) == NULL)
    return (NULL);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = node;
  node->prev = tmp;
  return (list);
}

t_list		*sup_elem(t_list *list, char *elem)
{
  t_list	*tmp;

  tmp = list;
  while (tmp && (my_strcmp(tmp->data, elem) != 0))
    tmp = tmp->next;
  if (tmp == NULL)
    return (list);
  else if (tmp->prev == NULL)
    {
      list = list->next;
      free(tmp);
    }
  else if (tmp->next == NULL)
    {
      tmp->prev->next = NULL;
      free(tmp);
    }
  else
    {
      tmp->prev->next = tmp->next;
      free(tmp);
    }
  return (list);
}

t_list		*create_list(char **tab)
{
  int		i;
  t_list	*list;
  t_list	*tmp;
  t_list	*node;

  i = 1;
  if ((list = create_node_list(tab[0])) == NULL)
    return (NULL);
  tmp = list;
  while (tab[i])
    {
      if ((node = create_node_list(tab[i])) == NULL)
	return (NULL);
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = node;
      node->prev = tmp;
      i++;
    }
  return (list);
}
