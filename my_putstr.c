/*
** my_putstr.c for  in /home/anthony.piot/projet/Librairy/libnew/Source
**
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
**
** Started on  Tue Feb 14 13:56:08 2017 Anthony PIOT
** Last update Fri Feb 17 10:57:00 2017 Hugo Perier
*/

#include "navy.h"

int	my_putstr(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (my_strlen(str));
}

int	my_puttab(char **tab)
{
  int	i;

  if (tab == NULL)
    return (0);
  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}

int     my_put_nbr(int nb)
{
  int   div;
  int   nb_stock;

  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  div = 1;
  nb_stock = nb;
  while (nb >= 10)
    {
      nb = nb / 10;
      div = div * 10;
    }
  nb = nb_stock;
  while (div > 0)
    {
      my_putchar(nb / div + '0');
      nb = nb % div;
      div = div / 10;
    }
  return (0);
}

int     my_strlen(char *str)
{
  int   i;

  if (str == NULL)
      return (0);
  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
