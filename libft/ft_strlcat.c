/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:22:47 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/19 13:32:28 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	u;
	size_t	y;
	size_t	z;

	i = 0;
	u = 0;
	y = 0;
	z = 0;
	while (dst[u] != '\0')
		u++;
	while (src[i] != '\0')
		i++;
	if (u > size)
		return (i + size);
	y = u;
	while (src[z] != '\0' && y + 1 < size)
	{
		dst[y] = src[z];
		y++;
		z++;
	}
	dst[y] = '\0';
	return (u + i);
}
