/*
** set_type.c for set_type.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/lexer
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Tue Aug 30 17:12:52 2016 jeremy thiriez
** Last update Sun Sep 11 14:12:32 2016 jeremy thiriez
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mysh.h"

int		type_cmd(t_ms *ms, char *str)
{
  int		i;
  int		ret;
  char		**tmp_path;

  i = -1;
  ret = -1;
  tmp_path = NULL;
  if (ms->all_path == NULL)
    return (-1);
  if (((tmp_path = my_cpy_tab(tmp_path, ms->all_path)) == NULL)
      || (add_path_and_cmd(tmp_path, str) == NULL))
    return (-2);
  while (tmp_path[++i] && ret == -1)
    ret = access(tmp_path[i], F_OK | X_OK);
  if (ret == 0)
    ret = i - 1;
  free_tab(tmp_path);
  return (ret);
}

int		type_ope(t_lexer *tmp)
{
  if (tmp->data[0][0] == ';')
    {
      tmp->type = DOT_COMA;
      return (-1);
    }
  else if (tmp->data[0][0] == '|')
    {
      tmp->type = PIPE;
      return (-1);
    }
  else if (tmp->data[0][0] == '<' || tmp->data[0][0] == '>')
    {
      tmp->type = REDI;
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		set_type(t_ms *ms)
{
  t_lexer	*tmp;
  bool		cmd;

  tmp = ms->lexer;
  cmd = true;
  while (tmp)
    {
      if (tmp->type > 1)
	{
	  if (cmd == true && def_in_ope(tmp->data[0], 0) == 0)
	    {
	      tmp->type = CMD;
	      cmd = false;
	    }
	  else if (type_ope(tmp) == -1)
	    cmd = true;
	  else if (type_ope(tmp) == EXIT_FAILURE)
	    tmp->type = ARG;
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
