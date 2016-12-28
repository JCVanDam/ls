/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 10:23:07 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/19 16:23:47 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_char(char *str, int i, char c)
{
	if (str[i] == c)
		return (0);
	else
		return (1);
}

static int		ft_count_word(char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (!(check_char(str, i, c)))
			while (!(check_char(str, i, c)) && (str[i] != '\0'))
				i++;
		else
		{
			while (check_char(str, i, c) && str[i] != '\0')
				i++;
			j++;
		}
	}
	return (j);
}

static int		*ft_count_letter(char *str, int *num_letter, char c)
{
	int i;
	int a;
	int j;

	i = 0;
	a = 1;
	j = 0;
	while (str[i] != '\0')
	{
		if (!(check_char(str, i, c)))
			while (!(check_char(str, i, c)) && (str[i] != '\0'))
				i++;
		else
		{
			while ((check_char(str, i, c)) && (str[i] != '\0'))
			{
				num_letter[j] = a;
				i++;
				a++;
			}
			a = 1;
			j++;
		}
	}
	return (num_letter);
}

static void		ft_add_char(char *str, char **tab, char c)
{
	int i;
	int a;
	int b;

	i = 0;
	a = 0;
	b = 0;
	while (str[i] != '\0')
	{
		if (!(check_char(str, i, c)))
			while ((!(check_char(str, i, c)) && str[i] != '\0'))
				i++;
		else
		{
			while ((check_char(str, i, c)) && (str[i] != '\0'))
			{
				tab[a][b] = str[i];
				i++;
				b++;
			}
			tab[a][b] = '\0';
			b = 0;
			a++;
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;
	int		*num_letter;
	int		words;

	i = 0;
	words = ft_count_word((char *)s, c);
	if (!(num_letter = (int*)malloc(sizeof(num_letter) * words + 1)))
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(tab) * words + 1)))
		return (NULL);
	ft_count_letter((char *)s, num_letter, c);
	num_letter[words] = '\0';
	while (i != words)
	{
		tab[i] = (char*)malloc(sizeof(char*) * num_letter[i] + 1);
		i++;
	}
	tab[words] = NULL;
	ft_add_char((char *)s, tab, c);
	return (tab);
}
