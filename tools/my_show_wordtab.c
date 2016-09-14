/*
** my_show_wordtab.c for my_show_wordtab.c in /home/thirie_a/maxi_save/tech_1/Prog_System_Unix/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sun Aug 28 21:59:03 2016 jeremy thiriez
** Last update Sun Sep 11 14:37:49 2016 jeremy thiriez
*/

#include "mysh.h"

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i += 1;
    }
}
