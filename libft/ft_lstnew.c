/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:11:59 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/06 17:40:40 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tmp->content_size = 0;
		tmp->content = NULL;
	}
	else
	{
		tmp->content_size = content_size;
		tmp->content = ft_memmove(ft_memalloc(content_size),
		content, content_size);
	}
	tmp->next = NULL;
	return (tmp);
}
