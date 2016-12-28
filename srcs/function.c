/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:06:03 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 11:03:39 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putstr_without(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] != '\n'))
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		ft_find_char(char *arg, char c)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr_str(char *str1, char *str2, char *str3, char *str4)
{
	if (str1)
		ft_putstr(str1);
	if (str2)
		ft_putstr(str2);
	if (str3)
		ft_putstr(str3);
	if (str4)
		ft_putstr(str4);
}
