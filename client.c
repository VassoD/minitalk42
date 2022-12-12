/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoropou <vdoropou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:15:08 by vdoropou          #+#    #+#             */
/*   Updated: 2022/12/12 18:36:52 by vdoropou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#define SLEEP_TIME 100

void	char_to_binary(char c, int pid)
{
	int	i;

	i = 8;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(SLEEP_TIME);
	}
}

void	string_to_binary(char *str, int pid)
{
	if (pid <= 1)
		return ;
	while (*str)
	{
		char_to_binary(*str, pid);
		str++;
	}
	char_to_binary('\0', pid);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		string_to_binary(argv[2], atoi(argv[1]));
	else
		write (1, "Usage: [Server PID] [Message]", 29);
	return (0);
}
