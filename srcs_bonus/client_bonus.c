/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:37:04 by eujeong           #+#    #+#             */
/*   Updated: 2022/12/13 14:44:42 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

static volatile t_signal	g_sig;

void	send_signal(pid_t pid, int sig)
{
	if (kill(pid, sig) != 0)
	{
		ft_putstr_fd("Failed to send signal. kill(", 1);
		ft_putnbr_fd(pid, 1);
		ft_putstr_fd(", ", 1);
		ft_putnbr_fd(sig, 1);
		ft_putstr_fd(")\n", 1);
		exit(1);
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_sig.pid != info->si_pid)
		return ;
	g_sig.signal = sig;
}

void	send_msg(int pid, char *str)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & (1 << (7 - j)))
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			while (g_sig.signal == 0)
				;
			if (g_sig.signal == SIGUSR1)
				j++;
			else if (g_sig.signal == SIGUSR2)
				usleep(500000);
			g_sig.signal = 0;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	if (argc != 3)
		return (0);
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	sigaddset(&(act.sa_mask), SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		ft_putstr_fd("SIGUSR1 sigaction error\n", 1);
		return (1);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		ft_putstr_fd("SIGUSR2 sigaction error\n", 1);
		return (1);
	}
	g_sig.pid = ft_atoi(argv[1]);
	send_msg(g_sig.pid, argv[2]);
	return (0);
}
