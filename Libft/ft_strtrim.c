/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:32:38 by eujeong           #+#    #+#             */
/*   Updated: 2022/07/13 13:38:18 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		check[256];
	size_t	i;
	size_t	j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	ft_memset(check, 0, sizeof(check));
	i = 0;
	while (set != NULL && set[i])
		check[(unsigned char)set[i++]] = 1;
	i = 0;
	j = ft_strlen(s1) - 1;
	while (i <= j && check[(unsigned char)s1[i]])
		i++;
	while (i < j && check[(unsigned char)s1[j]])
		j--;
	ret = (char *)malloc(sizeof(char) * (j - i + 2));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1 + i, j - i + 2);
	return (ret);
}
