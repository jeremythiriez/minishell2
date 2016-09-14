/*
** redi_right.c for redi_right.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/ope
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Mon Sep  5 13:28:54 2016 jeremy thiriez
** Last update Sun Sep 11 10:02:27 2016 jeremy thiriez
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"

int		redi_right(char *file, t_ms *ms)
{
  int		fd;

  if ((fd = open(file, O_WRONLY | O_TRUNC | O_CREAT,
		 0644)) == -1)
    return (EXIT_FAILURE);
  ms->stdout = dup(1);
  dup2(fd, 1);
  close(fd);
  ms->ret_val = 1;
  return (EXIT_SUCCESS);
}

int		double_redi_right(char *file, t_ms *ms)
{
  int		fd;

  if ((fd = open(file, O_WRONLY | O_CREAT | O_APPEND,
		 0644)) == -1)
    return (EXIT_FAILURE);
  ms->stdout = dup(1);
  dup2(fd, 1);
  close(fd);
  ms->ret_val = 1;
  return (EXIT_SUCCESS);
}

int		redi_left(t_tree *racine, char **arg)
{
  int		i;
  int		len;

  i = 0;
  while (arg[i])
    {
      len = my_len_tab(racine->data);
      if ((racine->data = realloc_tab(racine->data)) == NULL)
	return (EXIT_FAILURE);
      racine->data[len] = arg[i];
      racine->data[len + 1] = 0;
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int		redi(t_tree *racine, t_ms *ms)
{
  if (my_strcmp(">", racine->data[0]) == 0)
    if (redi_right(racine->right->data[0], ms) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  if (my_strcmp("<", racine->data[0]) == 0)
    if (redi_left(racine->left, racine->right->data) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  if (my_strcmp(">>", racine->data[0]) == 0)
    if (double_redi_right(racine->right->data[0], ms) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  if (my_strcmp("<<", racine->data[0]) == 0)
      if (double_redi_left(racine->right->data[0]) == EXIT_FAILURE)
	return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
