/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:41:44 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/10 12:04:30 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	i--;
	while ((int)i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

char	*ft_strrchr_without(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	i--;
	while (((int)i >= 0) && (s[i] == (char)c))
		i--;
	while ((int)i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i + 1]);
		i--;
	}
	return (NULL);
}
