/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:06:18 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 11:00:56 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_isdir(char *path)
{
	t_stat				stat_test;
	DIR					*dir;

	if (stat(path, &stat_test) == -1)
	{
		ft_putstr_str("ls: ", path, ": ", NULL);
		perror("");
		return (0);
	}
	if (S_ISDIR(stat_test.st_mode))
	{
		if (!(dir = opendir(path)))
		{
			ft_putstr_str("ls: ", path, ": ", NULL);
			perror("");
			return (0);
		}
		return (2);
	}
	if (S_ISREG(stat_test.st_mode))
		return (1);
	return (0);
}

int		ft_check_in_current_file(t_list **lst, char *path)
{
	DIR					*dir;
	t_dirent			*file;
	char				*tmp;
	char				*str;

	str = ft_strrchr_r(path, '/');
	dir = opendir(str);
	free(str);
	tmp = ft_take_end(path);
	while ((file = readdir(dir)))
		if (!ft_strcmp(tmp, file->d_name))
			if (!ft_create_lst(lst, path, file->d_name, 1))
				return (1);
	if (closedir(dir) == -1)
		return (1);
	free(tmp);
	return (0);
}
