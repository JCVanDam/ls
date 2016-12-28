/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:42:29 by maxpetit          #+#    #+#             */
/*   Updated: 2016/04/04 20:38:28 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	if (!(*little))
		return ((char *)big);
	while (len && (*big))
	{
		i = 0;
		if (*little == *big)
		{
			j = len;
			while (big[i] == little[i] && big[i] && little[i] && len)
			{
				len--;
				i++;
			}
			if (little[i] == '\0')
				return ((char *)big);
			len = j;
		}
		len--;
		big++;
	}
	return (NULL);
}
