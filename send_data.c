/*
** sec.c for sec in /home/hugo.perier/Projet
**
** Made by Perier Hugo
** Login   <hugo.perier@epitech.net>
**
** Started on  Mon Jan 30 16:46:52 2017 Perier Hugo
** Last update Sun Feb 19 15:28:30 2017 Hugo Perier
*/

#include "navy.h"

int	*getnbr(int *nb, char *str)
{
  nb[0] = ((str[0] - 64) * 2);
  nb[1] = (str[1] - 47);
  return (nb);
}

int	verif_signal(char *str, int i)
{
  char	stock;

  if (i == 0 && my_strlen(str) != 2)
    return (84);
  if (str[i] >= '0' && str[i] <= '8')
    {
      if (LETTER_CAPI(str[i + 1]) || LETTER_LOW(str[i + 1]))
	{
	  stock = str[i + 1] - ((LETTER_LOW(str[i + 1])) ? 32 : 0);
	  str[i + 1] = str[i];
	  str[i] = stock;
	  return (0);
	}
      return (84);
    }
  else if (str[i + 1] >= '0' && str[i + 1] <= '8')
    {
      if (LETTER_CAPI(str[i]) || LETTER_LOW(str[i]))
	{
	  str[i] = str[i] - ((str[i] >= 'a' && str[i] <= 'h') ? 32 : 0);
	  return (0);
	}
      return (84);
    }
  return (84);
}

int	*send_signal(int pid, int i)
{
  int	*nb;
  char	*str;
  int	*cpynb;

  cpynb = malloc(sizeof(int) * 3);
  nb = malloc(sizeof(int) * 3);
  str = get_next_line(1);
  if (verif_signal(str, 0) == 84)
    return (NULL);
  my_putstr(str);
  nb = getnbr(nb, str);
  cpynb = getnbr(cpynb, str);
  while (i != 2)
    {
      while (nb[i] != 0)
	{
	  kill(pid, SIGUSR1);
	  usleep(1000);
	  nb[i]--;
	}
      kill(pid, SIGUSR2);
      usleep(5);
      i++;
    }
  return (cpynb);
}
