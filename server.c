#include "minitalk.h"

int print_buffer(int size)
{
    write(1, buffer, size);
    return (0);
}

void    build_string(int byte)
{
    static char c;
    static int counter;
    static int  buffer_counter;

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
            buffer[buffer_counter++] = c;
        }
        c = 0;
    }
    else
        c <<= 1;
}

void    handle_sigusr1()
{
    build_string(1);
}

void    handle_sigusr2()
{
    build_string(0);
}

int main(void)
{
    int					pid;

	pid = getpid (); // get the process id
    write (1, "Server PID: ", 12); // print the process id
    ft_putnbr (pid); // convert the process id to a number
	write (1, "\n", 1); // print a new line
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);
    while (1)
    {
    }
    return (0);
}