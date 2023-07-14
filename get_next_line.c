/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:14:14 by bamsyah           #+#    #+#             */
/*   Updated: 2023/07/14 17:11:12 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *store)
{
	char	*buffer;
	ssize_t		rread;

	rread = 1;
	while(!newline_exist(store) && rread != 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		rread = read(fd, buffer, BUFFER_SIZE);
		if (rread == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[rread] = '\0';
		store = ft_strjoin(store, buffer);
	}
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*tmp;
	//char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read_file(fd, store);
	return tmp;

}
int main ()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
