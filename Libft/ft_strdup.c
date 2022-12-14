/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:20:39 by eujeong           #+#    #+#             */
/*   Updated: 2022/07/29 15:33:54 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*str2;
	size_t	len;

	len = ft_strlen(str1);
	str2 = malloc(sizeof(char) * (len + 1));
	if (str2 == NULL)
		return (NULL);
	ft_strlcpy(str2, str1, len + 1);
	return (str2);
}
