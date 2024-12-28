/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:44:32 by ahbilla           #+#    #+#             */
/*   Updated: 2024/12/28 10:04:45 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk_utils.c"

static void send_bit(int pid, char c)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(400);
        i--;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "Usage: ./client <server PID> <message>\n", 40);
        return (1);
    }
    int server_pid = ft_atoi(argv[1]);
    if (server_pid < 0)
    {
        write(1, "Server PID must be positive", 28);
        return 1;
    }
    if (!is_numeric(argv[1]))
    {
        write(1, "Error: server PID must be a number.\n", 36);
        return 1;
    }
    if (kill(server_pid, 0) == -1)
    {
        write(1, "No Server is running with this PID", 34);
        return 1;
    }
    char *message = argv[2];
    while (*message)
    {
        send_bit(server_pid, *message);
        message++;
    }
    send_bit(server_pid, '\0');
    return 0;
}