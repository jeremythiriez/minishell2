/*
** my_strlen.c for my_strlen.c in /home/thirie_a/maxi_save/tech_1/Prog_System_Unix/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sun Aug 28 22:20:52 2016 jeremy thiriez
** Last update Thu Sep  1 05:53:22 2016 jeremy thiriez
*/

#include "mysh.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
	i += 1;
    }
  return (i);
}
