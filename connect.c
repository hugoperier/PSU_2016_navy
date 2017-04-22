/*
** connect.c for  in /home/anthony.piot/projet/Sistm_Unix/navy
**
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
**
** Started on  Mon Jan 30 19:33:51 2017 Anthony PIOT
** Last update Sun Feb 19 10:15:18 2017 Anthony PIOT
*/

#include "navy.h"

int		redir(int sig)
{
  static int	i = 0;

  if (sig != 0)
    i = sig;
  return (i);
}

void	get_sigint(int sig)
{
  redir(sig);
}

int	conection(int ac, char **av, int etape)
{
  if (ac == 2)
    {
      etape = 0;
      my_putstr("waiting for enemy connection...\n");
      while (redir(0) != 10)
	signal(SIGUSR1, get_sigint);
      if (redir(0) == 10)
	my_putstr("enemy connected\n\n");
    }
  else if (ac == 3)
    {
      etape = 1;
      if (kill(my_getnbr(av[1]), SIGUSR1) == -1)
	{
	  my_putstr("connection fail\n\n");
	  return (84);
	}
      else
	my_putstr("successfully connected\n\n");
    }
  return (etape);
}
