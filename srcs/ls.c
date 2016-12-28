/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:08:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 11:06:38 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_by_option(t_list **lst, char *arg)
{
	ft_sort(lst);
	if (T)
		ft_sort_time(lst);
	if (R_MIN)
		ft_lst_reverse(lst);
}

int		ft_manage_dir(t_list **lst, char *path, t_filedata data)
{
	DIR					*dir;
	t_dirent			*file;

	if (!(dir = opendir(path)))
	{
		if (data.dir)
		{
			ft_putstr_str("ls: ", path, ": ", NULL);
			perror("");
			return (1);
		}
		else
			ft_check_in_current_file(lst, path);
	}
	else
	{
		while ((file = readdir(dir)))
			if (!ft_create_lst(lst, path, file->d_name, 0))
				return (1);
		if (closedir(dir) == -1)
			return (1);
	}
	return (0);
}

int		ft_ls(t_list *lst, char *path, t_filedata data)
{
	ft_print_name(path, data);
	if (!ft_manage_dir(&lst, path, data))
	{
		ft_sort_by_option(&lst, data.arg);
		ft_print_list(&lst, path, data);
		while (lst)
		{
			if (R && ft_check_dir(lst, data.arg) && data.dir)
				ft_ls(NULL, ((t_entity *)lst->content)->path, data);
			ft_del_elem(&lst);
		}
		return (1);
	}
	return (0);
}

void	ft_begin_ls(t_list *lst, char *arg, int dir, char **tab)
{
	int			i;
	t_filedata	data;
	static int	type_arg;
	static int	file_exist;

	i = 0;
	ft_sort_by_option(&lst, arg);
	if (dir && file_exist && lst)
		ft_putchar('\n');
	while (lst)
	{
		type_arg++;
		data.arg = arg;
		data.type_arg = type_arg;
		data.dir = dir;
		data.file_exist = file_exist;
		data.original_path = ((t_entity *)lst->content)->path;
		data.fst_path = tab[i++];
		if (!ft_ls(NULL, LST_PATH, data) && dir && lst->next)
			ft_putchar('\n');
		ft_del_elem(&lst);
	}
	if (type_arg && !dir)
		file_exist++;
}
