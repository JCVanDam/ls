/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 15:05:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/27 18:40:21 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	add_min(t_list *list, int (*cmp)())
{
	t_list *turtle;
	t_list *rabbit;
	t_list *stick;

	stick = list;
	while (stick->next->next != list && list->next != list
				&& list->next->next != list)
	{
		turtle = stick->next;
		rabbit = stick->next->next;
		while (rabbit != list)
		{
			if (cmp(turtle->data, rabbit->data) > 0)
				turtle = rabbit;
			else
				rabbit = rabbit->next;
		}
		rabbit = turtle->next;
		turtle->next = stick->next;
		stick->next = turtle;
		stick = turtle;
		while (turtle->next != stick)
			turtle = turtle->next;
		turtle->next = rabbit;
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *tmp;

	if (*begin_list && begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *begin_list;
		tmp = (*begin_list)->next;
		while (*begin_list != tmp)
		{
			if (cmp((*begin_list)->data, tmp->data) > 0)
				*begin_list = tmp;
			tmp = tmp->next;
		}
		*begin_list = tmp;
		add_min(*begin_list, cmp);
		while (tmp->next != *begin_list)
			tmp = tmp->next;
		tmp->next = NULL;
	}
}
