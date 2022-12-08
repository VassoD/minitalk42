#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
#define SLEEP_TIME 100
#define BUFFER_SIZE 100
char buffer[BUFFER_SIZE];

void	ft_putchar(char c);
int     t_atoi(const char *nptr);
void	ft_putnbr(int n);
#endif