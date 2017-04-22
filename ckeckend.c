/*
** ckeckend.c for  in /home/anthony.piot/Test/PSU_2016_navy/PSU_2016_navy
** 
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
** 
** Started on  Thu Feb  2 15:28:57 2017 Anthony PIOT
** Last update Thu Feb  2 15:29:47 2017 Anthony PIOT
*/

#include "navy.h"

int	checkmap(char **map)
{
  int	i;
  int	y;
  int	compteur;

  i = 0;
  y = 0;
  compteur = 0;
  while (map[y] != NULL)
    {
      if (map[y][i] == 'x')
	compteur++;
      i++;
      if (i == 18)
	{
	  i = 0;
	  y++;
	}
    }
  if (compteur == 14)
    return (1);
  return (0);
}

int	checkend(char **my_map, char **ennemy_map)
{
  int	my;
  int	ennemy;

  my = checkmap(my_map);
  ennemy = checkmap(ennemy_map);
  if (my == 1)
    return (0);
  else if (ennemy == 1)
    return (1);
  return (-1);
}
