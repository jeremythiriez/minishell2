/*
** my_len_tab.c for my_len_tab.c in /home/thirie_a/maxi_save/tech_1/Prog_System_Unix/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sun Aug 28 22:11:27 2016 jeremy thiriez
** Last update Sun Aug 28 22:12:07 2016 jeremy thiriez
*/

#include "mysh.h"

int		my_len_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
