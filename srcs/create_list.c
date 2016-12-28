/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:25:28 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 11:02:39 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_create_lst(t_list **lst, char *path, char *name, int dir)
{
	t_entity	*tmp;

	tmp = ft_create_elem(path, name, dir);
	if (tmp)
	{
		ft_lst_push_back(lst, tmp, sizeof(t_entity));
		free(tmp);
		return (1);
	}
	return (0);
}

t_entity	*ft_create_elem(char *path, char *file_name, int dir)
{
	t_entity	*tmp;

	if (!(tmp = (t_entity *)malloc(sizeof(t_entity))))
		return (NULL);
	ft_bzero(tmp, sizeof(t_entity));
	tmp->path = (dir) ? ft_strdup(path) : ft_put_endpath(path, file_name);
	if (lstat(tmp->path, &tmp->stat) == -1)
	{
		ft_putstr_str("ls: ", path, ": ", NULL);
		perror("");
		free(tmp);
		return (NULL);
	}
	tmp->type = ft_define_type(tmp->stat.st_mode);
	return (tmp);
}
