/*
** my_show_list.c for my_show_list.c in /home/thirie_a/maxi_save/tech_1/Prog_System_Unix/PSU_2015_minishell2/tools
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sun Aug 28 19:35:37 2016 jeremy thiriez
** Last update Tue Aug 30 18:20:40 2016 jeremy thiriez
*/

#include "mysh.h"

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      my_putstr(tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
