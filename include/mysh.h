/*
** mysh.h for mysh.h in /home/thirie_a/maxi_save/tech_1/Prog_System_Unix/PSU_2015_minishell2/include
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sun Aug 28 19:31:03 2016 jeremy thiriez
** Last update Sun Sep 11 20:18:07 2016 jeremy thiriez
*/

#ifndef MYSH_H
# define MYSH_H

# include <stdio.h>
# include <stdbool.h>

/*
**### COLOR ###
*/
# define ORANGE "\033[1;31m"
# define GREEN "\033[34m"
# define PINK "\033[32m"
# define RED "\033[1;36m"
# define YELLOW "\033[39m"
# define NORMAL "\033[0m"

/*
**### ERROR MSG ###
*/
# define PARS_INV "Invalid null command.\n"
# define TOO_MANY_ARG "Too many arguments.\n"
# define TOO_FEW_ARG "Too few arguments.\n"
# define NO_DIR ": Not a directory.\n"
# define NO_S_D ": No such file or directory\n"
# define ERR_REDI "Missing name for redirect.\n"
# define CMD_NOT_FOUND ": Command not found.\n"
# define AMBI_OUT "Ambiguous output redirect.\n"
# define ERR_ENV "»: Aucun fichier ou dossier de ce type\n"

/*
**### VAR ENV ###
*/
# define PATH "PATH="
# define HOME "HOME="
# define USER "USER="

/*
**### TYPES ####
*/
# define BEGIN 0
# define END 1
# define DOT_COMA 3
# define PIPE 4
# define REDI 5
# define CMD 6
# define ARG 7

typedef struct		s_list
{
  char			*data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef struct		s_tree
{
  char			**data;
  int			type;
  bool			on;
  struct s_tree		*left;
  struct s_tree		*right;
}			t_tree;

typedef struct		s_lexer
{
  char			**data;
  int			type;
  struct s_lexer	*next;
  struct s_lexer	*prev;
}			t_lexer;

typedef struct		s_ms
{
  int			ret_wait;
  int			ret_val;
  int			stdout;
  int			stdin;

  int			pid_dad;

  int			pipefd[2];
  t_tree		*tree;
  t_lexer		*lexer;
  char			**env;
  char			**all_path;
  char			*pwd;
  char			**cut_pwd;
}			t_ms;

/*
**########## TOOLS ##########
*/
int			my_puterr(char *str);
int			my_putstr(char *str);
int			my_strlen(char *str);
int			free_tab(char **tab);
int			free_lexer(t_lexer *lexer);
int			my_len_tab(char **tab);
int			my_begin_match(char *s1, char *s2);
int			my_strcmp(char *s1, char *s2);
int			my_put_nbr(int nb);
int			def_in_ope(char *str, int i);
int			my_getnbr(char *str);
char			*join_string(char *s1, char *s2);
char			*my_strcat(char *dest, char *src);
char			*my_strcpy(char *s1, char *s2);
char			**my_split_word_ope(char *str);
char			*get_next_line(const int fd);
char			*epur_str(char *str);
char			**my_split_slash(char *str);
char			**my_cpy_tab(char **dest, char **src);
char			**add_path_and_cmd(char **tab, char *cmd);
char			**realloc_tab(char **tab);
char			*my_strdup(char *src);
char			*my_getenv(char **env, char *elem);
char			**my_str_to_word_tab(char *str);
char			*my_add_cmd_in_path(char *dest, char *src);
char			*my_realloc(char *str, int size_add);
void			my_show_wordtab(char **tab);
void			my_putchar(char c);
void			my_show_list(t_list *list);
void			my_show_lexer(t_lexer *lexer);
t_list			*create_list(char **tab);

/*
**########## LEXER/PARSER ##########
*/
t_lexer			*create_lexer(char **av);
int			set_type(t_ms *ms);
int			parse_error(char *ope);
int			check_ope(char *str);
int			modif_lexer(t_lexer *lexer);
int			swap_redi(t_lexer *lexer);
int			create_tree(t_ms *ms);
int			err_lexer(t_lexer *lexer, t_ms *ms);
int			type_cmd(t_ms *ms, char *str);
int			add_color_ls(t_lexer *lexer);

/*
**########## BUILTINS ##########
*/
char			**my_setenv(char **env, char **tab);
char			*add_egal(char *str);
char			**my_unsetenv(char **env, char **cmd);
int			my_echo(char **tab, int fd);
int			check_builtins(char **cmd);
int			exec_builtins(char **cmd, t_ms *ms);
int			my_exit(t_ms *ms, char **cmd);
int			my_env(char **cmd, t_ms *ms);
int			my_cd(char **cd, t_ms *ms);
int			set_pwd(t_ms *ms, char *pwd);
int			find_pwd(t_ms *ms);
int			swap_pwd(t_ms *ms);

/*
**########## OPE ##########
*/
int			redi_right(char *file, t_ms *ms);
int			double_redi_right(char *file, t_ms *ms);
int			redi(t_tree *racine, t_ms *ms);
int			my_pipe_fork(t_ms *ms, t_tree *racine);
int			err_pipe(t_tree *racine, t_ms *ms);
int			double_redi_left(char *cmd);
int			my_pipe(t_ms *ms, t_tree *tree);

/*
**########## MINISHELL ##########
*/
int			minishell2(t_ms *ms);
int			run_tree(t_tree *racine, t_ms *ms);
int			exec_bin(t_ms *ms, char **env, char **cmd);
int			path_absolu(t_tree *tree, t_ms *ms);

/*
**########## MINISHELL ##########
*/
void			ambi_out(t_ms *ms);
void			err_redi(t_ms *ms);
void			pars_inv(t_ms *ms);
#endif /* !MYSH_H */
