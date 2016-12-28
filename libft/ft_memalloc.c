/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:48:32 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/09 13:16:20 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buf;
	size_t	i;

	i = 0;
	if (!(buf = (void *)malloc(size)))
		return (NULL);
	while (i < size)
	{
		((char *)buf)[i] = 0;
		i++;
	}
	return (buf);
}
