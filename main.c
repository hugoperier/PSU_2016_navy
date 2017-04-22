/*
** main.c for  in /home/anthony.piot/projet/Sistm_Unix/navy
**
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
**
** Started on  Mon Jan 30 18:44:00 2017 Anthony PIOT
** Last update Sun Feb 19 15:28:49 2017 Hugo Perier
*/

#include "navy.h"

void	print_maps(t_nav *navi)
{
  my_putstr("my positions:\n");
  my_puttab(navi->my_map);
  my_putstr("\nenemy's positions:\n");
  my_puttab(navi->enemy_map);
  my_putchar('\n');
}

int	flag_h(int ac, char **av)
{
  if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    {
      my_putstr("USAGE\n");
      my_putstr("\t./navy [first_player_pid] navy_positions\n\n");
      my_putstr("DESCRIPTION\n");
      my_putstr("\tfirst_player_pid\tonly for the 2nd player.");
      my_putstr("\tpid of the first player.\n");
      my_putstr("\tnavy_positions");
      my_putstr("\tfile representing the positions of the ships.\n");
      return (1);
    }
  return (0);
}

int	part3(t_nav *navi)
{
  print_maps(navi);
  if (checkend(navi->my_map, navi->enemy_map) == 0)
    {
      my_putstr("Enemy won\n");
      return (0);
    }
  else if (checkend(navi->my_map, navi->enemy_map) == 1)
    {
      my_putstr("I won\n");
      return (1);
    }
  return (0);
}

int	part2(int ac, t_nav *navi, int etape)
{
  int	*data;

  while (checkend(navi->my_map, navi->enemy_map) == - 1)
    {
      if ((ac == 2 && etape == 0) || (ac == 3 && etape == 1))
	print_maps(navi);
      if (etape == 1)
	{
	  my_putstr("waiting for enemy's attack...\n");
	  data = get_signal();
	  affpos(data);
	  navi->my_map = checktouch(data, navi->my_map, navi->enemi_pid);
	  etape = 0;
	}
      else if (etape == 0)
	{
	  my_putstr("attack: ");
	  while ((data = send_signal(navi->enemi_pid, 0)) == NULL)
	    my_putstr("wrong position\nattack: ");
	  navi->enemy_map = checkhit(navi->enemy_map, data);
	  etape = 1;
	}
    }
  return (part3(navi));
}

int	main(int ac, char **av)
{
  int	etape;
  t_nav	*navi;

  etape = 0;
  if (flag_h(ac, av) == 1)
    return (0);
  navi = malloc(sizeof(t_nav));
  if ((navi->my_map = aff_map(((ac == 2) ? av[1] : av[2]))) == NULL)
    return (84);
  navi->enemy_map = getmap(navi->enemy_map);
  my_putstr("my_pid: ");
  my_put_nbr(getpid());
  my_putchar('\n');
  if ((etape = conection(ac, av, etape)) == 84)
    return (84);
  get_pid_enemy(ac, av, navi);
  return (part2(ac, navi, etape));
}
