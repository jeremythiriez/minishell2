/*
** my_putchar.c for my_putchar.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_minishell1/tools
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Mon Jun 13 19:10:13 2016 jeremy thiriez
** Last update Wed Aug 31 14:19:17 2016 jeremy thiriez
*/

#include <unistd.h>
#include "mysh.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
