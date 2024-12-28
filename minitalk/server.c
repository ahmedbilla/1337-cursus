/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:27:09 by ahbilla           #+#    #+#             */
/*   Updated: 2024/12/28 11:38:30 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk_utils.c"
#include <libc.h>

void received_bit(int signal, siginfo_t *info, void *context)
{
	static int bits = 0;
	static char byte = 0;
	static int previous_pid;

	(void)context;
	if (previous_pid != info->si_pid)
	{
		previous_pid = info->si_pid;
		bits = 0;
		byte = 0;
	}
	byte = byte << 1;
	if (signal == SIGUSR2)
		byte |= 1;
	bits++;
	if (bits == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte, 1);
		bits = 0;
		byte = 0;
	}
}

void init_action(void)
{
	struct sigaction action;

	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = received_bit;
	if (sigaction(SIGUSR1, &action, NULL) == -1 || sigaction(SIGUSR2, &action, NULL) == -1)
		exit(1);
}

int main(int argc, char **argv)
{
	int pid;

	(void)argv;
	if (argc != 1)
		exit(1);
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	init_action();
	while (1)
		pause();
}

// int main(int argc, char *argv[])
// {
//     if (argc == 1)
//     {
//     pid_t PID;

//     PID = getpid();
//     write(1, "PID: ", 5);
//     ft_putnbr(PID);
//     write(1, "\n", 1);
//     struct sigaction mo;
//     mo.sa_flags = 0;
//     sigemptyset(&mo.sa_mask);
//     mo.sa_handler = received_bit;
//     // signal(SIGUSR1, received_bit);
//     // signal(SIGUSR2, received_bit);
//     sigaction(SIGUSR1, &mo, NULL);
//     sigaction(SIGUSR2, &mo, NULL);

//     while(1)
//         pause();

//     }
//      return (0);
// }