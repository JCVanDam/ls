/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:59:42 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 13:14:16 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_initialize_int(size_t *nblink, size_t *dev, size_t *size)
{
	*nblink = 0;
	*dev = 0;
	*size = 0;
}

void	ft_initialize(size_t *uid, size_t *gid)
{
	*uid = 0;
	*gid = 0;
}

void	ft_return_sizeint(t_list *lst, int option, char *path)
{
	static size_t	nblink;
	static size_t	dev;
	static size_t	size;
	char			*rdev;

	if (option == 1)
	{
		rdev = LST_RDEV;
		nblink = (nblink > SIZE_NLINK) ? nblink : SIZE_NLINK;
		dev = (dev > SIZE_RDEV) ? dev : SIZE_RDEV;
		size = (size > SIZE_SIZE) ? size : SIZE_SIZE;
		free(rdev);
	}
	else if (option == 2)
	{
		while (lst && (ft_strstr(((t_entity *)lst->content)->path, path)))
		{
			((t_entity *)lst->content)->buf_size.nblink = nblink;
			((t_entity *)lst->content)->buf_size.dev = dev;
			((t_entity *)lst->content)->buf_size.size = size;
			lst = lst->next;
		}
		ft_initialize_int(&nblink, &dev, &size);
	}
}

void	ft_return_size(t_list *lst, int option, char *path)
{
	t_passwd		*passwd;
	t_group			*group;
	static size_t	uid;
	static size_t	gid;

	if (option == 1)
	{
		passwd = getpwuid(((t_entity *)lst->content)->stat.st_uid);
		group = getgrgid(((t_entity *)lst->content)->stat.st_gid);
		if (passwd)
			uid = (uid > SIZE_USER) ? uid : SIZE_USER;
		if (group)
			gid = (gid > SIZE_GROUP) ? gid : SIZE_GROUP;
	}
	else if (option == 2)
	{
		while (lst && (ft_strstr(((t_entity *)lst->content)->path, path)))
		{
			((t_entity *)lst->content)->buf_size.uid = uid;
			((t_entity *)lst->content)->buf_size.gid = gid;
			lst = lst->next;
		}
		ft_initialize(&uid, &gid);
	}
}
