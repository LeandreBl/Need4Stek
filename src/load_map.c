/*
** load_map.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 20:57:19 2017 Léandre Blanchard
** Last update Thu May  4 20:59:47 2017 Léandre Blanchard
*/

#include "n4s.h"

static char	*get_string_file(const char *pathname)
{
  char		*s;
  int		fd;
  int		size;

  if ((fd = open(pathname, O_RDONLY)) < 0)
    return (NULL);
  size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, 0);
  if ((s = my_calloc(size + 1)) == NULL)
    return (NULL);
  if ((read(fd, s, size)) < 0)
    return (NULL);
  if (s[my_strlen(s) - 1] == '\n')
    s[my_strlen(s) - 1] = 0;
  close(fd);
  return (s);
}

char            **load_map(const char *pathname)
{
  char          *s;
  char          **map;
  int		i;

  i = 0;
  if ((s = get_string_file(pathname)) == NULL)
    return (NULL);
  if ((map = my_str_to_wordtab(s, '\n')) == NULL)
    return (NULL);
  free(s);
  if (tablen(map) < 4 || my_strlen(map[0]) < 4)
    {
      free_tab(&map);
      return (NULL);
    }
  while (map[i] != NULL)
    revstr(map[i++]);
  return (map);
}
