/*
** fct_useful.c for fct_useful.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_minishell1/src
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Jun 14 20:46:01 2016 jeremy thiriez
** Last update Tue Aug 30 19:35:14 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char		**add_path_and_cmd(char **path, char *cmd)
{
  int		i;

  i = 0;
  while (path[i])
    {
      if ((path[i] =
	   my_realloc(path[i], my_strlen(cmd) + 1)) == NULL)
	return (NULL);
      path[i] = my_add_cmd_in_path(path[i], cmd);
      i++;
    }
  return (path);
}
