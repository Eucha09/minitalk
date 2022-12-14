/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:53:29 by eujeong           #+#    #+#             */
/*   Updated: 2022/07/29 16:01:34 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newlst_cur;
	t_list	*cur;

	newlst = ft_lstnew(NULL);
	if (newlst == NULL || lst == NULL || f == NULL)
		return (NULL);
	newlst_cur = newlst;
	cur = lst;
	while (cur)
	{
		newlst_cur->next = ft_lstnew(f(cur->content));
		if (newlst_cur->next == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newlst_cur = newlst_cur->next;
		cur = cur->next;
	}
	newlst_cur = newlst;
	newlst = newlst->next;
	ft_lstdelone(newlst_cur, del);
	return (newlst);
}
