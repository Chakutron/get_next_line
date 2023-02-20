/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:24:00 by mchiboub          #+#    #+#             */
/*   Updated: 2023/02/18 12:04:47 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup2(void)
{
	char	*str;

	str = malloc(0);
	if (!str)
		return (NULL);
	return (str);
}

static char	*write_buffer(int fd, char *buffer)
{
	char	*str;
	int		readed;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	readed = 1;
	while (ft_strchr2(str, '\n') < 0 && readed > 0)
	{
		readed = read(fd, str, BUFFER_SIZE);
		if (readed < 0)
		{
			free(str);
			return (NULL);
		}
		str[readed] = '\0';
		if (readed > 0)
			buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

static char	*work_the_buffer(char *buffer)
{
	int		i;
	char	*str;

	i = ft_strchr2(buffer, '\n');
	if (i == -1)
		return (ft_strdup2());
	if (i == -2)
		i = ft_strlen(buffer);
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy2(str, buffer, i);
	ft_substr2(buffer, i + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[65534];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer[fd] = write_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (!ft_strlen(buffer[fd]))
	{
		free(buffer[fd]);
		return (NULL);
	}
	line = work_the_buffer(buffer[fd]);
	return (line);
}
