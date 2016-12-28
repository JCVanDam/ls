/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 20:59:19 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/20 19:45:19 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	while ((s1[i]) && (s2[i]) && (s1[i] == s2[i]) && (i < n))
		i++;
	if ((i == ft_strlen(s1)) || (i == n))
		return (1);
	else
		return (0);
}
