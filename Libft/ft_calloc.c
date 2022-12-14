/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:13:34 by eujeong           #+#    #+#             */
/*   Updated: 2022/08/02 17:43:12 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;

	if (size && ((num * size) / size != num))
		return (NULL);
	arr = malloc(num * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, num * size);
	return (arr);
}
