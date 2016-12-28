/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:05:43 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/21 17:08:51 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && n)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	if (!src[i] && n)
		while (n)
		{
			dest[i] = '\0';
			n--;
			i++;
		}
	return (dest);
}
