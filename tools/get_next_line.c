/*
** get_next_line.c for get_next_line.c in /home/thirie_a/tech_1/GNL/CPE_2015_getnextline
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Jun  7 11:15:53 2016 jeremy thiriez
** Last update Wed Aug 31 13:15:32 2016 jeremy thiriez
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "get_next_line.h"

char		*my_strcpy(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (s1 != NULL)
    {
      while (s1[i])
	{
	  s2[i] = s1[i];
	  i++;
	}
      s2[i] = 0;
    }
  return (s2);
}

char		*my_realloc(char *str, int size_add)
{
  char		*tmp;
  int		size;

  size = 0;
  while (str[size])
    size++;
  if ((tmp = malloc(sizeof(char) * (size + size_add + 1))) == NULL)
    return (NULL);
  tmp = my_strcpy(str, tmp);
  free(str);
  return (tmp);
}

int		check_buff(char *buff, int data)
{
  int		j;

  j = 0;
  if (data == 0)
    while (buff[j])
      {
	buff[j] = buff[j + 1];
	j++;
      }
  else
    while (buff[j])
      j++;
  return (j);
}

int		read_file(t_gnl *gnl, char *buff, const int fd)
{
  if (buff[0] == 0)
    {
      if ((gnl->ret = read(fd, buff, READ_SIZE)) == 0)
	return (EXIT_FAILURE);
      buff[gnl->ret] = 0;
      if ((gnl->dest = my_realloc(gnl->dest, gnl->ret)) == NULL)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  t_gnl		gnl;

  gnl.i = 0;
  gnl.ret = 1;
  if ((gnl.dest = malloc(sizeof(char) * (check_buff(buff, 1) + 1))) == NULL)
    return (NULL);
  gnl.dest[0] = 0;
  while (buff[0] != '\n' && gnl.ret > 0)
    {
      if ((read_file(&gnl, buff, fd)) == EXIT_FAILURE)
	return (NULL);
      while (buff[0] != '\n' && buff[0] != 0)
	{
	  gnl.dest[gnl.i] = buff[0];
	  check_buff(buff, 0);
	  gnl.i++;
	}
      gnl.dest[gnl.i] = 0;
    }
  check_buff(buff, 0);
  return (gnl.dest);
}
