/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <bamsyah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:23 by bamsyah           #+#    #+#             */
/*   Updated: 2023/07/16 14:41:52 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *buffer)
{
	int	i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *buffer, char *rest)
{
	char	*all;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!buffer)
		return (NULL);
	if (rest == NULL)
		return (ft_strdup(buffer));
	all = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(rest)) + 1);
	if (!all)
		return (NULL);
	while (rest && rest[i])
	{
		all[i] = rest[i];
		i++;
	}
	while (buffer[y])
	{
		all[i++] = buffer[y++];
	}
	all[i] = '\0';
	free(rest);
	return (all);
}

char	*ft_strdup(char *str)
{
	char	*sstr;
	int		i;

	i = 0;
	sstr = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!sstr)
		return (NULL);
	while (str[i])
	{
		sstr[i] = str[i];
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
