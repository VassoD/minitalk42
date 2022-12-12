/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoropou <vdoropou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:51:09 by vdoropou          #+#    #+#             */
/*   Updated: 2022/12/12 20:45:42 by vdoropou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#define BUFFER_SIZE 100

char	g_buffer[BUFFER_SIZE];

int	print_buffer(int size)
{
	write(1, g_buffer, size);
	return (0);
}

void	build_string(int byte)
{
	static char	c;
	static int	counter;
	static int	buffer_counter;

	c |= (byte == 1);
	if (counter++ == 8)
	{
		counter = 0;
		if (c == '\0')
			buffer_counter = print_buffer(buffer_counter);
		else
		{
			if (buffer_counter == BUFFER_SIZE)
				buffer_counter = print_buffer(buffer_counter);
			g_buffer[buffer_counter++] = c;
		}
		c = 0;
	}
	else
		c <<= 1;
}

void	handle_sigusr1()
{
	build_string(1);
}

void	handle_sigusr2(void)
{
	build_string(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write (1, "Server PID: ", 12);
	ft_putnbr (pid);
	write (1, "\n", 1);
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	while (1)
	{
	}
	return (0);
}
