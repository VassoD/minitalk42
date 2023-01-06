/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoropou <vdoropou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:15:08 by vdoropou          #+#    #+#             */
/*   Updated: 2022/12/14 19:45:44 by vdoropou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#define SLEEP_TIME 150

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
	while (*str)
	{
		char_to_binary(*str, pid);
		str++;
	}
	char_to_binary('\0', pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (write (2, "Usage: [Server PID] [Message]\n", 31), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		return (write (2, "Error : Invalid PID.\n", 22), 1);
	else
		string_to_binary(argv[2], pid);
	return (0);
}
