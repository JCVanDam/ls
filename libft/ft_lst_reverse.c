/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/29 19:13:28 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_reverse(t_list **begin_list)
{
	t_list *tmp;
	t_list *tmp1;
	t_list *tmp2;

	if (*begin_list && begin_list && ((*begin_list)->next))
	{
		tmp = *begin_list;
		tmp1 = NULL;
		tmp2 = NULL;
		tmp1 = tmp->next;
		tmp->next = NULL;
		tmp2 = tmp1->next;
		tmp1->next = tmp;
		while (tmp2)
		{
			tmp = tmp1;
			tmp1 = tmp2;
			tmp2 = tmp2->next;
			tmp1->next = tmp;
		}
		*begin_list = tmp1;
		return (*begin_list);
	}
	return (NULL);
}
