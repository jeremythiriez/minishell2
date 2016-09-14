/*
** get_next_line.h for get_next_line.h in /home/thirie_a/tech_1/GNL/CPE_2015_getnextline
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Jun  7 11:10:50 2016 jeremy thiriez
** Last update Sun Jun 19 20:02:51 2016 Live session user
*/

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (14)
# endif /* !READ_SIZE */

typedef struct	s_gnl
{
  char		*dest;
  int		ret;
  int		i;
}		t_gnl;

char		*get_next_line(const int fd);
void		my_putchar(char c);
int		my_putstr(char *str);

#endif /* !_GET_NEXT_LINE_H_ */
