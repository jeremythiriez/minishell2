/*
** path_abslolu.c for pat_absolu.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/minishell
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Sun Sep 11 05:47:59 2016 jeremy thiriez
** Last update Sun Sep 11 05:55:40 2016 jeremy thiriez
*/

#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int		path_absolu(t_tree *racine, t_ms *ms)
{
  pid_t		pid;

  if (access(racine->data[0], F_OK | X_OK) != -1)
    {
      if ((pid = fork()) == -1)
	return (EXIT_FAILURE);
      if (pid == 0)
	execve(racine->data[0], racine->data, ms->env);
      else
	wait(NULL);
    }
  else
    {
      my_puterr(racine->data[0]);
      my_puterr(CMD_NOT_FOUND);
      ms->ret_val = 1;
    }
  return (EXIT_SUCCESS);
}
