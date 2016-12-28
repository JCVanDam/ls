/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:51:06 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 14:21:43 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_pad_free(char orientation, char *str, size_t size, char elem)
{
	char *new;

	new = ft_padding(orientation, str, size, elem);
	ft_putstr(new);
	if (ft_strcmp(new, str))
		free(new);
}

char	*ft_padding(char orientation, char *str, size_t size, char elem)
{
	size_t	i;
	char	*new;

	if ((size_t)ft_strlen(str) != size)
	{
		i = (orientation == 'L') ? 0 : (size_t)ft_strlen(str);
		new = ft_strnew((int)size);
		if (orientation == 'R')
			new = ft_strcpy(new, str);
		while ((size_t)ft_strlen(str) != size)
		{
			new[i] = elem;
			i++;
			size--;
		}
		if (orientation == 'L')
			new = ft_strcat(new, str);
		return (new);
	}
	return (str);
}

void	ft_print_nlink(t_list *lst)
{
	char		*num;

	ft_putstr("  ");
	num = LST_NLINK;
	ft_pad_free('L', num, LST_SIZE_NLINK, ' ');
	free(num);
	ft_putstr(" ");
}
