/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:54:20 by eujeong           #+#    #+#             */
/*   Updated: 2022/07/29 16:03:36 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		nbr_len;
	int		sign;
	char	*str;
	int		i;

	nbr_len = ft_nbrlen(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	str = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (str == NULL)
		return (NULL);
	str[nbr_len] = '\0';
	if (sign == -1)
		str[0] = '-';
	i = nbr_len - 1;
	while ((sign == 1 && i >= 0) || (sign == -1 && i >= 1))
	{
		str[i] = n % 10 * sign + '0';
		n /= 10;
		i--;
	}
	return (str);
}
