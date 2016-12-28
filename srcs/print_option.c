/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:54:33 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 14:19:33 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_link(char *path)
{
	char	*buf;
	size_t	bufsize;
	ssize_t	ret;

	bufsize = SIZE;
	buf = ft_memalloc(bufsize);
	if ((ret = readlink(path, buf, bufsize)) == -1)
		perror("");
	ft_putstr_str(" ", "->", " ", buf);
	free(buf);
}

void	ft_print_mode(t_list *lst)
{
	ft_putchar(LST_TYPE);
	(LST_PERM & S_IRUSR ? ft_putchar('r') : ft_putchar('-'));
	(LST_PERM & S_IWUSR ? ft_putchar('w') : ft_putchar('-'));
	if (!(LST_PERM & S_ISUID))
		(LST_PERM & S_IXUSR ? ft_putchar('x') : ft_putchar('-'));
	else
		(LST_PERM & S_IXUSR ? ft_putchar('s') : ft_putchar('S'));
	(LST_PERM & S_IRGRP ? ft_putchar('r') : ft_putchar('-'));
	(LST_PERM & S_IWGRP ? ft_putchar('w') : ft_putchar('-'));
	if (!(LST_PERM & S_ISGID))
		(LST_PERM & S_IXGRP ? ft_putchar('x') : ft_putchar('-'));
	else
		(LST_PERM & S_IXGRP ? ft_putchar('s') : ft_putchar('S'));
	(LST_PERM & S_IROTH ? ft_putchar('r') : ft_putchar('-'));
	(LST_PERM & S_IWOTH ? ft_putchar('w') : ft_putchar('-'));
	if (!(LST_PERM & S_ISVTX))
		(LST_PERM & S_IXOTH ? ft_putchar('x') : ft_putchar('-'));
	else
		(LST_PERM & S_IXOTH ? ft_putchar('t') : ft_putchar('T'));
}

void	ft_putmajmin(t_stat stat)
{
	int		major;
	int		minor;
	char	*str_major;
	char	*str_minor;

	ft_putstr(" ");
	major = (stat.st_rdev >> 24);
	minor = (stat.st_rdev) & 0xffffff;
	str_major = ft_itoa(major);
	str_minor = ft_itoa(minor);
	ft_pad_free('L', str_major, 2, ' ');
	ft_putchar(',');
	ft_pad_free('L', str_minor, 4, ' ');
	free(str_minor);
	free(str_major);
}

void	ft_print_size(t_list *lst, int spe_file, char *arg)
{
	char *num;

	if (spe_file == 1)
		(!A) ? ft_putstr("       ") : ft_putstr("    ");
	num = LST_SIZE;
	ft_pad_free('L', num, LST_SIZE_SIZE, ' ');
	free(num);
}

void	ft_print_stat(t_list *lst, int spe_file, char *arg)
{
	t_passwd	*passwd;
	t_group		*group;
	char		*str_time;

	ft_print_mode(lst);
	ft_print_nlink(lst);
	if ((passwd = getpwuid(LST_UID)))
		ft_pad_free('R', USER_NAME, LST_SIZE_UID, ' ');
	else
		ft_putstr(ft_itoa(((t_entity *)lst->content)->stat.st_uid));
	ft_putstr("  ");
	if ((group = getgrgid(LST_GID)))
		ft_pad_free('R', GROUP_NAME, LST_SIZE_GID, ' ');
	else
		ft_putstr(ft_itoa(((t_entity *)lst->content)->stat.st_gid));
	ft_putstr("  ");
	if ((LST_TYPE == 'b') || (LST_TYPE == 'c'))
		ft_putmajmin(((t_entity *)lst->content)->stat);
	else
		ft_print_size(lst, spe_file, arg);
	str_time = ft_cut_time(ctime(&LST_TIME), LST_TIME);
	ft_putstr_str(str_time, " ", NULL, NULL);
	free(str_time);
}
