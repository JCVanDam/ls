/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 15:05:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/05/29 19:14:48 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_list(t_list *list)
{
	int i;

	i = 0;
	while (list->next)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	ft_swap_data(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_list_reverse_fun_cool(t_list *begin_list, int i, int len)
{
	t_list	*turtle;
	t_list	*rabbit;
	t_list	*tmp;

	if (begin_list)
	{
		turtle = begin_list;
		rabbit = turtle;
		while (rabbit->next)
			rabbit = rabbit->next;
		ft_swap_data(&turtle->content, &rabbit->content);
		turtle = turtle->next;
		tmp = rabbit;
		rabbit = turtle;
		while (i++ <= (len / 2) - 1)
		{
			while (rabbit->next != tmp)
				rabbit = rabbit->next;
			ft_swap_data(&turtle->content, &rabbit->content);
			turtle = turtle->next;
			tmp = rabbit;
			rabbit = turtle;
		}
	}
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		len;

	if (begin_list)
	{
		len = ft_len_list(begin_list);
		ft_list_reverse_fun_cool(begin_list, 0, len);
	}
}
