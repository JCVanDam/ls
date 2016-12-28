/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:57:50 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 12:54:11 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_fill_arg(char *param, char *arg)
{
	int			i;
	static int	j;

	i = 0;
	while (param[++i])
	{
		if ((param[i] == 'l') || (param[i] == 'R') ||
				(param[i] == 'a') || (param[i] == 'r') || (param[i] == 't'))
		{
			if (!ft_find_char(arg, param[i]))
			{
				arg[j] = param[i];
				j++;
			}
		}
		else
		{
			ft_putstr_str("ls: illegal option -- ", &param[i], "\n", NULL);
			ft_putstr("usage: ls [-Ralrt]");
			ft_putstr_str(" [file ...]", "\n", NULL, NULL);
			return (1);
		}
	}
	return (0);
}

int		ft_check_path(char *str)
{
	int i;

	if (!ft_strcmp(str, "/"))
		return (1);
	i = ft_strlen(str) - 1;
	while (str[i] && str[i] == '/')
		i--;
	while ((i >= 0) && str[i])
	{
		if (str[i] == '/')
			return (1);
		i--;
	}
	return (0);
}

void	ft_free_struct(t_manage_arg *x)
{
	int	i;

	i = -1;
	while (++i <= x->i)
		free(x->f_file[i]);
	free(x->f_file);
	i = -1;
	while (++i <= x->j)
		free(x->f_dir[i]);
	free(x->f_dir);
}

void	ft_loop_arg(t_list *tab_file, t_list *tab_dir, char **argv, char *arg)
{
	t_manage_arg	x;

	x.i = -1;
	x.j = -1;
	x.f_file = (char **)ft_memalloc(sizeof(char *) * ft_strlen_tab(argv) + 1);
	x.f_dir = (char **)ft_memalloc(sizeof(char *) * ft_strlen_tab(argv) + 1);
	argv = (!ft_strcmp(*argv, "--")) ? argv + 1 : argv;
	while (*argv)
	{
		x.path = PATH ? ft_strdup(*argv) : ft_strjoin("./", *argv);
		x.ret = ft_check_isdir(x.path);
		if (x.ret == 1)
			if (ft_create_lst(&tab_file, x.path, NULL, 1) == 1)
				x.f_file[++x.i] = ft_strdup(*argv);
		if (x.ret == 2)
			if (ft_create_lst(&tab_dir, x.path, NULL, 1) == 2)
				x.f_dir[++x.j] = ft_strdup(*argv);
		free(x.path);
		argv++;
	}
	ft_begin_ls(tab_file, arg, 0, x.f_file);
	ft_begin_ls(tab_dir, arg, 1, x.f_dir);
	ft_free_struct(&x);
}

int		main(int argc, char **argv)
{
	int			i;
	char		*arg;
	t_filedata	data;

	i = argc - argc;
	arg = ft_strnew(5);
	while ((argv[++i]) && (argv[i][0] == '-') && (ft_strcmp(argv[i], "--")))
		if (ft_fill_arg(argv[i], arg))
			return (0);
	if (argv[i])
		ft_loop_arg(NULL, NULL, &argv[i], arg);
	else
	{
		data.dir = 1;
		data.arg = arg;
		data.type_arg = 0;
		data.original_path = ".";
		data.fst_path = ".";
		ft_ls(NULL, ".", data);
	}
	free(arg);
	return (0);
}
