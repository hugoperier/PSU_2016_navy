/*
** get_pid_enemy.c for  in /home/anthony.piot/projet/Sistm_Unix/navy
**
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
**
** Started on  Tue Jan 31 17:52:53 2017 Anthony PIOT
** Last update Fri Feb 17 16:13:09 2017 Hugo Perier
*/

#include "navy.h"

int		pid_go(int nb)
{
  static int	pid = 0;

  if (pid == 0)
    pid = nb;
  return (pid);
}

void	pid_emet(int sig, siginfo_t *info, void *context)
{
  context = context;
  sig = sig;
  pid_go(info->si_pid);
}

int			get_pid_enemy(int ac, char **av, t_nav *navi)
{
  struct sigaction	sa;

  sa.sa_sigaction = pid_emet;
  sa.sa_flags = SA_SIGINFO;
  if (ac == 2)
    {
      while (pid_go(0) == 0)
	{
	  sigaction(SIGUSR1, &sa, NULL);
	}
      navi->enemi_pid = pid_go(0);
    }
  else if (ac == 3)
    {
      usleep(1000);
      kill(my_getnbr(av[1]), SIGUSR1);
      navi->enemi_pid = my_getnbr(av[1]);
    }
  return (0);
}
