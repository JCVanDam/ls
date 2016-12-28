/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:42:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/06 13:52:25 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;

	if (!(*little))
		return ((char *)big);
	while (*big)
	{
		i = 0;
		if (*little == *big)
		{
			while (little[i] == big[i] && little[i] && big[i])
				i++;
			if (little[i] == '\0')
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
