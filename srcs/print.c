/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:18:00 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 14:21:44 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_total(int total)
{
	char *res;

	res = ft_itoa(total);
	ft_putstr_str("total ", res, "\n", NULL);
	free(res);
}

void	ft_loop_count(t_list *lst, int *spe_file, char *path, t_filedata data)
{
	int		total;
	int		count;
	char	*name;

	total = 0;
	count = 0;
	while (lst && (ft_strstr(LST_PATH, path)))
	{
		name = ft_take_end(LST_PATH);
		if ((LST_TYPE == 'b') || (LST_TYPE == 'c'))
			*spe_file = 1;
		if ((name[0] == '.') && !(ft_find_char(data.arg, 'a')))
			lst = lst->next;
		else
		{
			total = total + ((t_entity *)lst->content)->stat.st_blocks;
			ft_return_size(lst, 1, path);
			ft_return_sizeint(lst, 1, path);
			lst = lst->next;
			count++;
		}
		free(name);
	}
	if (count && data.dir)
		ft_print_total(total);
}

void	ft_loop_print(t_list **lst, int spe_file, char *path, t_filedata data)
{
	t_list	*tmp;
	char	*name;

	tmp = *lst;
	name = NULL;
	while (tmp && (ft_strstr(TMP_PATH, path)))
	{
		name = ft_take_end(TMP_PATH);
		if ((name[0] == '.') && !(ft_find_char(data.arg, 'a')))
			tmp = tmp->next;
		else
		{
			if (L)
				ft_print_stat(tmp, spe_file, data.arg);
			(!data.dir) ? ft_putstr(data.fst_path) : ft_putstr(name);
			if (TMP_TYPE == 'l')
				ft_display_link(TMP_PATH);
			ft_putstr("\n");
			tmp = tmp->next;
		}
		free(name);
	}
}

void	ft_print_list(t_list **lst, char *path, t_filedata data)
{
	int		spe_file;

	spe_file = 0;
	if (ft_find_char(data.arg, 'l'))
		ft_loop_count(*lst, &spe_file, path, data);
	ft_return_size(*lst, 2, path);
	ft_return_sizeint(*lst, 2, path);
	ft_loop_print(lst, spe_file, path, data);
}

void	ft_print_name(char const *path, t_filedata data)
{
	char	*print_path;

	if (((ft_strcmp(data.original_path, ".")
		&& (data.original_path[0] == '.')))
		&& (!(data.dir && data.type_arg)))
		print_path = ft_strdup(data.fst_path);
	else
		print_path = ft_strdup(path);
	if ((R && ft_strcmp(path, data.original_path))
		|| (data.dir && data.file_exist))
		ft_putstr_str(print_path, ":", "\n", NULL);
	free(print_path);
}
