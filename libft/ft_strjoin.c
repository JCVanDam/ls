/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:59:29 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/15 12:16:31 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = ft_strnew(((ft_strlen(s1)) + (ft_strlen(s2) + 1)));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;

	str = ft_strnew(((ft_strlen(s1)) + (ft_strlen(s2) + 1)));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	free(s1);
	return (str);
}
