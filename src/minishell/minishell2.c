/*
** minishell2.c for minishell2.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Wed Aug 31 04:27:49 2016 jeremy thiriez
** Last update Sun Sep 11 21:31:30 2016 jeremy thiriez
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int		prompt(t_ms *ms)
{
  if (find_pwd(ms) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  my_putstr(RED);
  my_putstr("<<");
  my_putstr(ORANGE);
  my_putstr(my_getenv(ms->env, USER));
  my_putstr(RED);
  my_putstr(">>");
  my_putstr(PINK);
  my_putstr("[");
  my_putstr(GREEN);
  my_putstr(ms->cut_pwd[my_len_tab(ms->cut_pwd) - 1]);
  my_putstr(PINK);
  my_putstr("]");
  my_putstr(YELLOW);
  my_putstr(" ➜ ");
  my_putstr(NORMAL);
  return (EXIT_SUCCESS);
}

int		reset_cmd_line(t_ms *ms)
{
  char		*cmd_line;

  ms->stdout = 1;
  ms->stdin = 0;
  if ((cmd_line = get_next_line(0)) == NULL)
    exit(ms->ret_val);
  cmd_line = epur_str(cmd_line);
  if (cmd_line[0] == 0)
    return (EXIT_FAILURE);
  if (((ms->lexer = create_lexer(my_split_word_ope(cmd_line))) == NULL)
      || (modif_lexer(ms->lexer) == EXIT_FAILURE)
      || (set_type(ms) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  swap_redi(ms->lexer);
  free(cmd_line);
  if ((err_lexer(ms->lexer, ms) == EXIT_FAILURE)
      || (create_tree(ms) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  ms->all_path = my_str_to_word_tab(my_getenv(ms->env, PATH));
  ms->ret_val = 0;
  return (EXIT_SUCCESS);
}

int		minishell2(t_ms *ms)
{
  while (42)
    {
      prompt(ms);
      if (reset_cmd_line(ms) == EXIT_SUCCESS)
	run_tree(ms->tree, ms);
      dup2(ms->stdout, 1);
      dup2(ms->stdin, 0);
    }
  return (EXIT_SUCCESS);
}
