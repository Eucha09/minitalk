/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:06:31 by eujeong           #+#    #+#             */
/*   Updated: 2022/12/13 14:38:35 by eujeong          ###   ########.fr       */
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
	}
}

void	receive_msg(void)
{
	static unsigned char	c;
	static int				cnt;
	pid_t					temp_pid;

	if (g_sig.signal == SIGUSR1)
		c = (c << 1) + 1;
	else if (g_sig.signal == SIGUSR2)
		c = (c << 1);
	cnt++;
	if (cnt == 8)
	{
		if (c == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		cnt = 0;
	}
	temp_pid = g_sig.pid;
	if (c == 0)
		g_sig.pid = 0;
	g_sig.signal = 0;
	send_signal(temp_pid, SIGUSR1);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_sig.signal != 0 || (g_sig.pid != 0 && g_sig.pid != info->si_pid))
	{
		send_signal(info->si_pid, SIGUSR2);
		return ;
	}
	g_sig.signal = sig;
	if (g_sig.pid == 0)
		g_sig.pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&(act.sa_mask));
	act.sa_flags = SA_SIGINFO | SA_NODEFER;
	act.sa_sigaction = handler;
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
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
	while (1)
	{
		if (g_sig.signal == 0)
			continue ;
		receive_msg();
	}
	return (0);
}
