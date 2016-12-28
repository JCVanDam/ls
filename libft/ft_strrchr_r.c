/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:23:15 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/15 14:15:19 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr_r(const char *str, int c)
{
	int		i;
	char	*new;

	i = ft_strlen(str);
	while (i >= 0 && str[i] == c)
		i--;
	while (i >= 0 && str[i] != c)
		i--;
	if (str[i] == c)
	{
		new = ft_strnew(i);
		new = ft_strncpy(new, str, i);
		return (new);
	}
	return (NULL);
}
