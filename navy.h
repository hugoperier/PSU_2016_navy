/*
** navy.h for  in /home/anthony.piot/projet/Sistm_Unix/navy
**
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
**
** Started on  Mon Jan 30 18:46:54 2017 Anthony PIOT
** Last update Sun Feb 19 15:29:17 2017 Hugo Perier
*/

#ifndef NAVY_H_
# define NAVY_H_

#define WIDTH		19
#define READ_SIZE	10
#define HEIGHT		12
#define LETTER_CAPI(c)	(c >= 'A' && c <= 'H')
#define LETTER_LOW(c)	(c >= 'a' && c <= 'h')
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

typedef struct	s_pos
{
  int		fx;
  int		fy;
  int		tx;
  int		ty;
  char		c;
}		t_pos;

typedef struct	s_nav
{
  char		**my_map;
  char		**enemy_map;
  int		enemi_pid;
  int		etape;
}		t_nav;

int	get_pid_enemy(int , char **, t_nav *);
void	pid_emet(int, siginfo_t *, void *);
int	pid_go(int);

int	conection(int, char **, int);
void	get_sigint(int);
int	redir(int);

char	**getmap(char **);
char	**put_ship(char **, char *);
t_pos	get_pos(char *, t_pos);
char	**aff_map(char *);

char	*my_strcpy(char *, char *);
char	*get_next_line(const int);

int	*v_protocol(int);
void	redir2(int);
int	boo(int, int);
int	*get_signal();
int	*getnbr(int *, char *);
int	*send_signal(int, int);
char	**checktouch(int *, char **, int);
int	istouch(int);
char	**checkhit(char **, int *);
int	verif_map(char *);
int	verif_signal(char *, int);
void	affpos(int *);
int	checkend(char **, char **);

#endif /* !NAVY_H_ */
