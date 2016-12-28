/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:46:21 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/19 19:37:05 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)) ||
	((c >= 48) && (c <= 57)))
		return (1);
	return (0);
}
