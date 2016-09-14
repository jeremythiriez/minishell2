/*
** my_getenv.c for my_getenv.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_minishell1
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Jun 14 03:22:12 2016 jeremy thiriez
** Last update Tue Aug 30 18:49:00 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

char		*my_getenv(char **env, char *elem)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (elem[j])
    j++;
  while (env[i])
    {
      if (my_begin_match(env[i], elem) == 0)
	return (env[i] + j);
      i += 1;
    }
  return (NULL);
}
