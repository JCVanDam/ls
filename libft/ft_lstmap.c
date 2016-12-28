/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:16:49 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/21 17:42:38 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;
	t_list	*rabbit;
	t_list	*turtle;

	cpy = NULL;
	if (lst)
	{
		cpy = f(lst);
		cpy = ft_lstnew(cpy->content, cpy->content_size);
		if (!cpy)
			return (NULL);
		lst = lst->next;
	}
	rabbit = cpy;
	while (lst)
	{
		turtle = rabbit;
		rabbit = f(lst);
		rabbit = ft_lstnew(rabbit->content, rabbit->content_size);
		if (!rabbit)
			return (NULL);
		turtle->next = rabbit;
		lst = lst->next;
	}
	return (cpy);
}
