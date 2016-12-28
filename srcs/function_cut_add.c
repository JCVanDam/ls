/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_cut&add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 21:27:29 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/16 11:08:17 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_put_endpath(char *path, char *file_name)
{
	char *tmp;

	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin_free(tmp, file_name);
	return (tmp);
}

char	*ft_take_end(char *path)
{
	int		i;
	int		j;
	int		len;
	char	*name;

	i = ft_strlen(path) - 1;
	j = 0;
	len = 0;
	if (ft_strcmp(path, "/") && path[i] == '/')
	{
		i--;
		len++;
	}
	while ((i >= 0) && (path[i] != '/'))
	{
		i--;
		len++;
	}
	name = ft_strnew(len);
	while (path[++i])
	{
		name[j] = path[i];
		j++;
	}
	return (name);
}

void	ft_more_six_month(char *str_time, char **str_new, int len, int i)
{
	char	*fst_part;
	char	*sd_part;

	len = 4;
	fst_part = ft_strsub(str_time, i, 7);
	sd_part = ft_strsub(str_time, ft_strlen(str_time) - 6, 5);
	*str_new = ft_strjoin_free(fst_part, " ");
	*str_new = ft_strjoin_free(*str_new, sd_part);
	free(sd_part);
}

char	*ft_cut_time(char *str_time, long int sec)
{
	int		i;
	int		j;
	int		len;
	char	*new;
	time_t	now;

	i = 0;
	len = 0;
	new = NULL;
	while (str_time[i] != ' ')
		i++;
	j = ft_strlen(str_time) + 1;
	if (sec < (time(&now) - SEC_SEX_MONTH))
		ft_more_six_month(str_time, &new, len, i);
	else
	{
		while (str_time[j] != ':')
			j--;
		len = j - i;
		new = ft_strsub(str_time, i, len);
	}
	return (new);
}
