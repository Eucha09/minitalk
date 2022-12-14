/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:42:40 by eujeong           #+#    #+#             */
/*   Updated: 2022/07/27 13:55:32 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (-10 < n && n < 10)
	{
		ft_putchar_fd(n * sign + '0', fd);
		return ;
	}
	ft_putnbr_fd(n / 10 * sign, fd);
	ft_putchar_fd(n % 10 * sign + '0', fd);
}
