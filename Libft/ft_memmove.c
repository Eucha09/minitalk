/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:59:03 by eujeong           #+#    #+#             */
/*   Updated: 2022/07/29 15:19:59 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (dst < src)
			((char *)dst)[i] = ((char *)src)[i];
		else
			((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
		i++;
	}
	return (dst);
}
