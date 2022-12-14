/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:08:47 by eujeong           #+#    #+#             */
/*   Updated: 2022/07/29 15:24:24 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char *)ptr)[i] == (unsigned char)value)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
