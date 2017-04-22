/*
** test.c for test in /home/hugo.perier/Projet
**
** Made by Perier Hugo
** Login   <hugo.perier@epitech.net>
**
** Started on  Mon Jan 30 15:12:32 2017 Perier Hugo
** Last update Wed Feb  1 17:25:28 2017 Hugo Perier
*/

#include "navy.h"

int	*v_protocol(int sig)
{
  static int a[2];
  static int i = 0;
  static int place = 0;

  if (sig == -1)
    {
      i = 0;
      place = 0;
      boo(0, 1);
    }
  if (sig == 10)
    i++;
  else if (sig == 12)
    {
      a[place] = i;
      i = 0;
      place++;
    }
  if (place == 2)
    {
      boo(1, 0);
    }
  return (a);
}

void	redir2(int sig)
{
  v_protocol(sig);
}

int	boo(int ac, int arg)
{
  static int bool = 0;

  bool += ac;
  if (arg == 1)
    bool = 0;
  return (bool);
}

int	*get_signal()
{
  int	*data;

  while (boo(0, 0) != 1)
    {
      signal(SIGUSR1, redir2);
      signal(SIGUSR2, redir2);
    }
  data = v_protocol(0);
  v_protocol(-1);
  return (data);
}
