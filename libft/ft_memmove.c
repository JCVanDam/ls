/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:36:02 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/06 17:36:03 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	if (!(tmp = (unsigned char *)malloc(sizeof(unsigned char) * n)))
		return (NULL);
	while (i < n)
	{
		tmp[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (dest);
}
