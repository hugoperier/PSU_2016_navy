/*
** my_getnbr.c for my_getnbr in /home/anthony.piot/projet/librairy/libmy
**
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
**
** Started on  Sat Nov 12 11:22:12 2016 Anthony PIOT
** Last update Sun Feb 19 15:35:34 2017 Hugo Perier
*/

#include "navy.h"

int	foix_gnbr(int i)
{
  int	nbr;

  nbr = 1;
  while (i > 0)
    {
      nbr = nbr * 10;
      i = i - 1;
    }
  return (nbr);
}

int	check_my_getnbr(char *str, int i)
{
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (84);
      i = i + 1;
    }
  return (0);
}

int	my_getnbr(char *charac)
{
  int	i;
  int	j;
  int	nb;
  int	n;

  if (charac == NULL)
    return (0);
  i = ((charac[0] == '-') ? 1 : 0);
  if (check_my_getnbr(charac, i) == 84)
    return (0);
  j = my_strlen(charac) - 1;
  nb = 0;
  while (i < my_strlen(charac))
    {
      n = (charac[j] - '0') * foix_gnbr(i - ((charac[0] == '-') ? 1 : 0));
      nb = nb + n;
      i = i + 1;
      j = j - 1;
    }
  if (charac[0] == '-')
    nb = nb * - 1;
  return (nb);
}
