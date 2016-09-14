##
## Makefile for makefile in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_minishell1
##
## Made by jeremy thiriez
## Login   <thirie_a@epitech.net>
##
## Started on  Fri Jun 10 18:54:32 2016 jeremy thiriez
## Last update Sun Sep 11 20:13:18 2016 jeremy thiriez
##

NAME	= mysh

CC	= gcc

RM	= rm -rf

SRCS	= src/main.c \
	  src/lexer/create_lexer.c \
	  src/lexer/set_type.c \
	  src/lexer/check_ope.c \
	  src/lexer/modif_lexer.c \
	  src/lexer/create_tree.c \
	  src/lexer/err_lexer.c \
	  src/lexer/msg_err.c \
	  src/lexer/color.c \
	  src/minishell/minishell2.c \
	  src/minishell/exec_cmd.c \
	  src/minishell/exec_bin.c \
	  src/minishell/path_absolu.c \
	  src/builtins/setenv.c \
	  src/builtins/my_env.c \
	  src/builtins/unsetenv.c \
	  src/builtins/add_egal.c \
	  src/builtins/echo.c \
	  src/builtins/my_exit.c \
	  src/builtins/my_cd.c \
	  src/builtins/check_builtin.c \
	  src/builtins/pwd.c \
	  src/ope/redi_right.c \
	  src/ope/double_redi_left.c \
	  src/ope/pipe_fork.c \
	  src/ope/err_pipe.c

TOOLS	= tools/my_putchar.c \
	  tools/my_putstr.c \
	  tools/my_getenv.c \
	  tools/my_show_list.c \
	  tools/my_show_lexer.c \
	  tools/my_show_wordtab.c \
	  tools/realloc_tab.c \
	  tools/my_len_tab.c \
	  tools/my_strlen.c \
	  tools/my_strcat.c \
	  tools/my_strdup.c \
	  tools/join_string.c \
	  tools/create_list.c \
	  tools/my_strcmp.c \
	  tools/my_getnbr.c \
	  tools/my_str_to_word_tab.c \
	  tools/my_add_cmd_in_path.c \
	  tools/add_path_and_cmd.c \
	  tools/my_begin_match.c \
	  tools/get_next_line.c \
	  tools/my_cpy_tab.c \
	  tools/my_put_nbr.c \
	  tools/free_tab.c \
	  tools/free_lexer.c \
	  tools/my_split_word_ope.c \
	  tools/my_split_slash.c \
	  tools/epur_str.c

CFLAGS	+= -W -Wall -Wextra -I./include -g3

OBJS	= $(SRCS:.c=.o) $(TOOLS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all re
