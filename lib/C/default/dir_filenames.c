/*
** dir_filenames.c for dir_filenames in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Sep 16 15:39:05 2017 Léandre Blanchard
** Last update Wed Nov  1 18:19:58 2017 Léandre Blanchard
*/

#include <sys/types.h>
#include <dirent.h>

#include "my.h"
#include "defines.h"

char		**dir_filenames(const char *dirname, int sort)
{
  char		**filenames;
  DIR		*directory;
  struct dirent	*dirent;

  filenames = NULL;
  if ((directory = opendir(dirname)) == NULL)
    return (NULL);
  while ((dirent = readdir(directory)) != NULL)
    if (dirent->d_type == DT_REG)
      if ((filenames = tab_append(filenames, my_strdup(dirent->d_name))) == NULL)
	return (NULL);
  closedir(directory);
  if (sort)
    sort_tab(filenames);
  return (filenames);
}
