/*
** msg_err.c for msg_err.c in /home/jeremy/rendu/PSU/PSU_2015_minishell2/src/lexer
**
** Made by jeremy thiriez
** Login   <jeremy@epitech.net>
**
** Started on  Sun Sep 11 16:35:33 2016 jeremy thiriez
** Last update Sun Sep 11 16:37:09 2016 jeremy thiriez
*/

#include "mysh.h"

void		ambi_out(t_ms *ms)
{
  my_puterr(AMBI_OUT);
  ms->ret_val = 1;
}

void		err_redi(t_ms *ms)
{
  my_puterr(ERR_REDI);
  ms->ret_val = 1;
}

void		pars_inv(t_ms *ms)
{
  my_puterr(PARS_INV);
  ms->ret_val = 1;
}
