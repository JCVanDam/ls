/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 16:29:00 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/15 17:13:43 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_find_min(t_list **entity)
{
	t_list *stick;
	t_list *turtle;
	t_list *rabbit;

	if (*entity && (*entity)->next && (*entity)->next->next)
	{
		stick = *entity;
		while (stick->next->next != *entity)
		{
			turtle = stick->next;
			rabbit = stick->next->next;
			while (rabbit != *entity)
			{
				if (CMP_PATH)
					turtle = rabbit;
				rabbit = rabbit->next;
			}
			while (rabbit->next != turtle)
				rabbit = rabbit->next;
			rabbit->next = turtle->next;
			turtle->next = stick->next;
			stick->next = turtle;
			stick = stick->next;
		}
	}
}

void	ft_sort(t_list **lst)
{
	t_list *stick;
	t_list *turtle;
	t_list *rabbit;

	if ((*lst) && (*lst)->next)
	{
		stick = *lst;
		turtle = *lst;
		rabbit = *lst;
		while (rabbit->next)
		{
			if (CMP_PATH_NXT)
				turtle = rabbit->next;
			rabbit = rabbit->next;
		}
		rabbit->next = stick;
		while (stick != turtle)
			stick = stick->next;
		ft_find_min(&stick);
		rabbit = stick;
		while (rabbit->next != turtle)
			rabbit = rabbit->next;
		rabbit->next = NULL;
		*lst = stick;
	}
}

void	ft_find_min_time(t_list **entity)
{
	t_list *stick;
	t_list *turtle;
	t_list *rabbit;

	if (*entity && (*entity)->next && (*entity)->next->next)
	{
		stick = *entity;
		while (stick->next->next != *entity)
		{
			turtle = stick->next;
			rabbit = stick->next->next;
			while (rabbit != *entity)
			{
				if (ft_cmp_time(turtle, rabbit))
					turtle = rabbit;
				rabbit = rabbit->next;
			}
			while (rabbit->next != turtle)
				rabbit = rabbit->next;
			rabbit->next = turtle->next;
			turtle->next = stick->next;
			stick->next = turtle;
			stick = stick->next;
		}
	}
}

void	ft_sort_time(t_list **lst)
{
	t_list *stick;
	t_list *turtle;
	t_list *rabbit;

	if ((*lst) && (*lst)->next)
	{
		stick = *lst;
		turtle = *lst;
		rabbit = *lst;
		while (rabbit->next)
		{
			if (ft_cmp_time(turtle, rabbit->next))
				turtle = rabbit->next;
			rabbit = rabbit->next;
		}
		rabbit->next = stick;
		while (stick != turtle)
			stick = stick->next;
		ft_find_min_time(&stick);
		rabbit = stick;
		while (rabbit->next != turtle)
			rabbit = rabbit->next;
		rabbit->next = NULL;
		*lst = stick;
	}
}

int		ft_cmp_time(t_list *turtle, t_list *rabbit)
{
	if (CMP_TIME)
		return (1);
	if (EGUAL_TIME)
	{
		if (CMP_NANOTIME)
			return (1);
		if (EGUAL_NANOTIME)
		{
			if (CMP_PATH)
				return (1);
		}
	}
	return (0);
}
