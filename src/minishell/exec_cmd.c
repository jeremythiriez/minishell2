/*
** exec_cmd.c for exec_cmd.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/minishell
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Mon Sep  5 10:53:57 2016 jeremy thiriez
** Last update Sun Sep 11 19:51:26 2016 jeremy thiriez
*/

#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int		exec_cmd(t_ms *ms, char **cmd, int i)
{
  pid_t		pid;
  char		**tmp_path;

  tmp_path = NULL;
  if (((tmp_path = my_cpy_tab(tmp_path, ms->all_path)) == NULL)
      || (add_path_and_cmd(tmp_path, cmd[0]) == NULL))
    return (EXIT_FAILURE);
  if ((pid = fork()) == -1)
    return (EXIT_FAILURE);
  if (pid == 0)
    execve(tmp_path[i], cmd, ms->env);
  else
    wait(NULL);
  free_tab(tmp_path);
  return (EXIT_SUCCESS);
}

int		run_cmd(t_tree *racine, t_ms *ms)
{
  int		i;

  if ((i = type_cmd(ms, racine->data[0])) > -1)
    {
      if (i == -2 ||
	  (exec_cmd(ms, racine->data, i)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    {
      exec_bin(ms, ms->env, racine->data);
      if (ms->ret_val == 0)
	ms->ret_val = 1;
    }
  return (EXIT_SUCCESS);
}

int		if_cmd(t_tree *racine, t_ms *ms)
{
  if (check_builtins(racine->data) == 1)
    {
      if (exec_builtins(racine->data, ms) == EXIT_FAILURE)
	return (EXIT_SUCCESS);
    }
  else if (my_begin_match(racine->data[0], "./") == 0)
    {
      if (exec_bin(ms, ms->env, racine->data) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (racine->data[0][0] == '/')
    {
      if (path_absolu(racine, ms) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (run_cmd(racine, ms) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		read_node(t_tree *racine, t_ms *ms)
{
  if (racine->on == true)
    {
      if (racine->type == REDI)
	if (redi(racine, ms) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
      if (racine->type == PIPE)
	if (my_pipe_fork(ms, racine) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
      if (racine->type == DOT_COMA)
	return (EXIT_SUCCESS);
      if (racine->type == CMD)
	{
	  if (if_cmd(racine, ms) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

int		run_tree(t_tree *racine, t_ms *ms)
{
  if (racine != NULL)
    {
      if (read_node(racine, ms) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (racine->left == NULL || racine->left->type == PIPE ||
	  (racine->type == PIPE && racine->right != NULL))
	return (EXIT_SUCCESS);
      run_tree(racine->left, ms);
      if (racine->type == DOT_COMA)
	{
	  ms->ret_val = 0;
	  dup2(ms->stdout, 1);
	  dup2(ms->stdin, 0);
	}
      run_tree(racine->right, ms);
    }
  return (EXIT_SUCCESS);
}
