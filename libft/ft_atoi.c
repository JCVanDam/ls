/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:18:56 by maxpetit          #+#    #+#             */
/*   Updated: 2016/12/28 14:54:25 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while ((*str == '\t' || *str == '\n' || *str == '\v' ||
	*str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '+') || (*str == '-'))
		str++;
	while ((*str) && ((*str >= 48) && (*str <= 57)))
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb * sign);
}
