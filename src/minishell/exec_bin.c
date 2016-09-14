/*
** exec_bin.c for exec_bin.c in /home/thirie_a/maxi_save/tech_1/Prog_System_Unix/PSU_2015_minishell1/src
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Fri Jul  8 17:49:49 2016 jeremy thiriez
** Last update Sun Sep 11 10:59:07 2016 jeremy thiriez
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include "mysh.h"

int		check_wait(t_ms *ms)
{
  ms->ret_val = WEXITSTATUS(ms->ret_wait);
  if (WIFSIGNALED(ms->ret_wait) == 1)
    {
      ms->ret_val = 128 + WTERMSIG(ms->ret_wait);
      if (ms->ret_val == 139)
	my_putstr("Segmentation fault\n");
      if (ms->ret_val == 136)
	my_putstr("Floating exception\n");
    }
  return (EXIT_FAILURE);
}

int		check_bin(t_ms *ms, char **cmd)
{
  struct stat	st;
  char		*dir;

  dir = cmd[0] + 2;
  stat(dir, &st);
  if (S_ISDIR(st.st_mode) == 1)
    {
      my_puterr(cmd[0]);
      my_puterr(": Permission denied.\n");
      ms->ret_val = 1;
      return (1);
    }
  return (0);
}

int		exec_bin(t_ms *ms, char **env, char **cmd)
{
  pid_t		pid;

  if (check_bin(ms, cmd) == 0)
    {
      if (access(cmd[0], F_OK | X_OK) == 0)
	{
	  if ((pid = fork()) == -1)
	    return (EXIT_FAILURE);
	  if (pid == 0)
	    execve(cmd[0], cmd, env);
	  else
	    {
	      wait(&ms->ret_wait);
	      check_wait(ms);
	    }
	}
      else
	{
	  my_puterr(cmd[0]);
	  my_puterr(": Command not found.\n");
	  ms->ret_val = 1;
	}
    }
  return (EXIT_SUCCESS);
}
