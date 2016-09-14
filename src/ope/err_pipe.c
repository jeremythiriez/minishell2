/*
** err_pipe.c for err_pipe.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/ope
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Sun Sep 11 06:57:16 2016 jeremy thiriez
** Last update Sun Sep 11 07:07:58 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		check_err_cmd(t_tree *racine, t_ms *ms)
{
  if (racine->type != PIPE && racine->type != 5)
    {
      if (type_cmd(ms, racine->data[0]) == -1)
	ms->ret_val = 1;
    }
  return (EXIT_SUCCESS);
}

int		err_pipe(t_tree *racine, t_ms *ms)
{
  if (racine != NULL)
    {
      check_err_cmd(racine, ms);
      err_pipe(racine->left, ms);
      err_pipe(racine->right, ms);
    }
  return (EXIT_SUCCESS);
}
