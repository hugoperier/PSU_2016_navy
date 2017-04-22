/*
** verif_map.c for  in /home/anthony.piot/Test/PSU_2016_navy/PSU_2016_navy
**
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
**
** Started on  Thu Feb  2 13:16:03 2017 Anthony PIOT
** Last update Fri Feb 17 16:22:44 2017 Hugo Perier
*/

#include "navy.h"

int	verif_shipsize2(int size, int foor, int five)
{
  if (size == 4)
    {
      if (foor == 0)
	return (84);
      foor = 0;
    }
  else if (size == 5)
    {
      if (five == 0)
	return (84);
      five = 0;
    }
  return (0);
}

int		verif_shipsize(int size)
{
  static int	two = 2;
  static int	three = 3;
  static int	foor = 4;
  static int	five = 5;

  if (size == 2)
    {
      if (two == 0)
	return (84);
      two = 0;
    }
  else if (size == 3)
    {
      if (three == 0)
	return (84);
      three = 0;
    }
  else
    verif_shipsize2(size, foor, five);
  return (0);
}

int	verif_map2(char *str, int i, int j, int k)
{
  i = str[3] - '0';
  j = str[6] - '0';
  k = ((i < j) ? j - (i - 1) : i - (j - 1));
  return (k);
}

int	verif_all(char *str, int i, int j, int k)
{
  i = i;
  j = j;
  k = k;
  if (my_strlen(str) != 7 || str[0] < '2' || str[0] > '5' ||
      verif_shipsize(str[0] - '0') == 84)
    return (84);
  if (verif_signal(str, 2) == 84 || verif_signal(str, 5) == 84)
    return (84);
  return (0);
}

int	verif_map(char *str)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  if (verif_all(str, i, j, k) == 84)
    return (84);
  if (str[2] == str[5])
    {
      if (verif_map2(str, i, j, k) != str[0] - '0')
	return (84);
    }
  else if (str[3] == str[6])
    {
      i = str[2] - 'A';
      j = str[5] - 'A';
      k = ((i < j) ? j - (i - 1) : i - (j - 1));
      if (k != str[0] - '0')
	return (84);
    }
  else
    return (84);
  return (0);
}
