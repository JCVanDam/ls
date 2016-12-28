/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:07:05 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 11:09:16 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		ft_define_type(unsigned long mode)
{
	if (S_ISREG(mode))
		return ('-');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISFIFO(mode))
		return ('f');
	if (S_ISLNK(mode))
		return ('l');
	return ('s');
}

int			ft_check_dir(t_list *lst, char *arg)
{
	char		*name;

	name = ft_take_end(((t_entity *)lst->content)->path);
	if (NO_HIDE_FILE && IS_DIR)
	{
		free(name);
		ft_putstr("\n");
		return (1);
	}
	if (CMP_CURRENT && CMP_PREVIOUS && HIDE_FILE && IS_DIR && A)
	{
		free(name);
		ft_putstr("\n");
		return (1);
	}
	free(name);
	return (0);
}

void		ft_del_elem_fstlst(t_list **lst)
{
	t_list *cpy;

	cpy = (*lst)->next;
	free((*lst)->content);
	free(*lst);
	*lst = cpy;
}

void		ft_del_elem(t_list **lst)
{
	t_list *cpy;

	cpy = (*lst)->next;
	free(((t_entity *)(*lst)->content)->path);
	free((*lst)->content);
	free(*lst);
	*lst = cpy;
}
