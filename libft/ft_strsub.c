/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:58:59 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/15 13:25:23 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start]))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
