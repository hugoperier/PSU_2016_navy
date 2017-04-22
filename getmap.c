/*
** main.c for main in /home/hugo/Projet/sysUnix/PSU_2016_navy
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Mon Jan 30 11:12:15 2017 Hugo Perier
** Last update Sun Feb 19 15:36:01 2017 Hugo Perier
*/

#include "navy.h"

char	**getmap(char **map)
{
  int	i;

  i = 0;
  map = malloc(sizeof(char *) * HEIGHT);
  while (i <= HEIGHT)
    {
      map[i] = malloc(sizeof(char) * WIDTH);
      i++;
    }
  map[0] = my_strcpy(map[0], " |A B C D E F G H");
  map[1] = my_strcpy(map[1], "-+---------------");
  map[2] = my_strcpy(map[2], "1|. . . . . . . .");
  map[3] = my_strcpy(map[3], "2|. . . . . . . .");
  map[4] = my_strcpy(map[4], "3|. . . . . . . .");
  map[5] = my_strcpy(map[5], "4|. . . . . . . .");
  map[6] = my_strcpy(map[6], "5|. . . . . . . .");
  map[7] = my_strcpy(map[7], "6|. . . . . . . .");
  map[8] = my_strcpy(map[8], "7|. . . . . . . .");
  map[9] = my_strcpy(map[9], "8|. . . . . . . .");
  map[10] = NULL;
  return (map);
}

char	**put_ship(char **map, char *ship)
{
  t_pos	pos;

  if ((pos = get_pos(ship, pos)).c == '\0')
    return (NULL);
  while ((pos.fx != pos.tx) || (pos.fy != pos.ty))
    {
      if (map[pos.fy][pos.fx] != '.')
	return (NULL);
      map[pos.fy][pos.fx] = pos.c;
      if (pos.fx != pos.tx)
	pos.fx = pos.fx + 2;
      if (pos.fy != pos.ty)
	pos.fy = pos.fy + 1;
    }
  if (map[pos.fy][pos.fx] != '.')
    return (NULL);
  map[pos.fy][pos.fx] = pos.c;
  return (map);
}

t_pos	get_pos(char *ship, t_pos pos)
{
  if (ship[1] != ':' || ship[4] != ':')
    {
      pos.c = '\0';
      return (pos);
    }
  pos.fx = (ship[2] - 64) * 2;
  pos.fy = (ship[3] - 47);
  pos.tx = (ship[5] - 64) * 2;
  pos.ty = (ship[6] - 47);
  pos.c = ship[0];
  return (pos);
}

char	**aff_map(char *file)
{
  char	**map;
  char	*ship;
  int	i;

  if ((i = open(file, 0)) == - 1)
    return (NULL);
  map = malloc(sizeof(char *) * HEIGHT);
  map = getmap(map);
  while ((ship = get_next_line(i)))
    {
      if (verif_map(ship) == 84 || (map = put_ship(map, ship)) == NULL)
	return (NULL);
    }
  close(i);
  return (map);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
