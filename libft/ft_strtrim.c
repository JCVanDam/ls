/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:59:57 by maxpetit          #+#    #+#             */
/*   Updated: 2016/04/05 15:41:52 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	size_t	i;

	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == ',')
		s++;
	i = 0;
	while (s[i])
		i++;
	while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t' ||
	s[i - 1] == '\n' || s[i - 1] == ','))
		i--;
	cpy = ft_strnew(i);
	if (!cpy)
		return (NULL);
	cpy = ft_strncpy(cpy, s, i);
	cpy[i] = '\0';
	return (cpy);
}
