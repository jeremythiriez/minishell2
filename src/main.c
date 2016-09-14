/*
** main.c for main.c in /home/thirie_a/maxi_save/tech_1/Prog_System_Unix/PSU_2015_minishell2/src
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sun Aug 28 19:28:41 2016 jeremy thiriez
** Last update Sun Sep 11 05:08:16 2016 jeremy thiriez
*/

#include <stdlib.h>
#include "mysh.h"

int		set_minishell(t_ms *ms, char **env)
{
  if (((ms->env = my_cpy_tab(ms->env, env)) == NULL)
      || (ms->all_path = my_str_to_word_tab(my_getenv(env, PATH))) == NULL)
    return (EXIT_FAILURE);
  ms->ret_val = 0;
  return (EXIT_SUCCESS);
}

void		end_prog(t_ms *ms)
{
  free_tab(ms->env);
  free_tab(ms->all_path);
  free_lexer(ms->lexer);
}

int		main(int ac, char **av, char **env)
{
  t_ms		ms;

  (void)ac;
  (void)av;
  if (set_minishell(&ms, env) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  minishell2(&ms);
  return (EXIT_SUCCESS);
}
