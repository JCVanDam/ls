/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:56:49 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/15 17:47:26 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nbrchar(char *nbr, int n, int i)
{
	while (n)
	{
		nbr[i] = '0' - (n % 10);
		n = n / 10;
		i--;
	}
	return (nbr);
}

char		*ft_itoa(int n)
{
	int		m;
	int		i;
	char	*nbr;

	i = -1;
	m = n;
	while (m)
	{
		m = m / 10;
		i++;
	}
	if (n <= 0)
		i++;
	if (!(nbr = ft_strnew(i + 1)))
		return (NULL);
	if (!nbr)
		return (NULL);
	if (n < 0)
		nbr[0] = '-';
	if (n > 0)
		n = -n;
	if (!n)
		nbr[0] = '0';
	return (ft_nbrchar(nbr, n, i));
}
