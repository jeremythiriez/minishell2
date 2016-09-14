/*
** pipe_fork.c for pipe_fork.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/ope
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Sat Sep 10 19:47:50 2016 jeremy thiriez
** Last update Sun Sep 11 19:35:06 2016 jeremy thiriez
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include "mysh.h"

int		exec_pipe(t_ms *ms, t_tree *racine)
{
  char		**tmp_path;
  int		i;

  tmp_path = NULL;
  if (check_builtins(racine->data) == 1)
    {
      exec_builtins(racine->data, ms);
      exit(0);
    }
  else if ((i = type_cmd(ms, racine->data[0])) > -1)
    {
      if (((tmp_path = my_cpy_tab(tmp_path, ms->all_path)) == NULL)
	  || (add_path_and_cmd(tmp_path, racine->data[0]) == NULL))
	return (EXIT_FAILURE);
      execve(tmp_path[type_cmd(ms, racine->data[0])], racine->data, ms->env);
    }
  else if (access(racine->data[0], F_OK | X_OK) == 0)
    execve(racine->data[0], racine->data, ms->env);
  else
    {
      my_puterr(racine->data[0]);
      my_puterr(CMD_NOT_FOUND);
      exit(1);
    }
  return (EXIT_SUCCESS);
}

int		son_pipe(int pipefd[2], t_ms *ms, t_tree *racine, struct stat *st)
{
  close(pipefd[0]);
  if (dup2(pipefd[1], 1) == -1)
    return (EXIT_FAILURE);
  if (racine->left->type == PIPE)
    {
      if (my_pipe(ms, racine->left) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (racine->left->data[1] != NULL && racine->left->data[1][0] != '-'
	   && (int)st->st_size > 64000)
    exit(1);
  else
    exec_pipe(ms, racine->left);
  exit(1);
  return (EXIT_SUCCESS);
}

int		dad_pipe(int pipefd[2], t_ms *ms, t_tree *racine)
{
  close(pipefd[1]);
  if (dup2(pipefd[0], 0) == -1)
    return (EXIT_FAILURE);
  if (racine->right->type == 5)
    {
      if (redi(racine->right, ms) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (exec_pipe(ms, racine->right->left) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    exec_pipe(ms, racine->right);
  return (EXIT_SUCCESS);
}

int		my_pipe(t_ms *ms, t_tree *racine)
{
  pid_t		pid;
  int		pipefd[2];
  struct stat	st;

  stat(racine->left->data[1], &st);
  if (pipe(pipefd) == -1)
    return (EXIT_FAILURE);
  if ((pid = fork()) == -1)
    return (EXIT_FAILURE);
  if (pid == 0)
    {
      if (son_pipe(pipefd, ms, racine, &st) == EXIT_FAILURE)
	exit(1);
    }
  else
    {
      wait(NULL);
      if (dad_pipe(pipefd, ms, racine) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		my_pipe_fork(t_ms *ms, t_tree *racine)
{
  pid_t		pid;

  racine->left->on = false;
  racine->right->on = false;
  err_pipe(racine, ms);
  if ((pid = fork()) == -1)
    return (EXIT_FAILURE);
  if (pid == 0)
    {
      if (my_pipe(ms, racine) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    wait(NULL);
  return (EXIT_SUCCESS);
}
