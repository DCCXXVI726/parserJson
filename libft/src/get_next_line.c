/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:36:57 by deladia           #+#    #+#             */
/*   Updated: 2019/07/11 19:31:52 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t		ft_check(char **file, char **line)
{
	size_t		i;
	char		*c_file;
	char		*tmp1;

	i = 0;
	c_file = *file;
	while (c_file[i] != '\n')
	{
		if (!c_file[i++])
			return (0);
	}
	tmp1 = &c_file[i];
	*tmp1 = '\0';
	*line = ft_strdup(*file);
	*file = ft_strdup(tmp1 + 1);
	free(c_file);
	return (1);
}

ssize_t		ft_read(const int fd, char *buf, char **file, char **line)
{
	ssize_t		ret;
	char		*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (*file)
		{
			tmp = *file;
			*file = ft_strjoin(tmp, buf);
			free(tmp);
			tmp = NULL;
		}
		else
			*file = ft_strdup(buf);
		if (ft_check(file, line) != 0)
			break ;
	}
	if (ret > 0)
		return (1);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*file[256];
	ssize_t		ret;
	char		*buf;

	if (fd < 0 || !line || (read(fd, file[0], 0) < 0) ||
			((buf = ft_memalloc(BUFF_SIZE + 1)) == NULL))
		return (-1);
	if (file[fd])
		if (ft_check(&file[fd], line) == 1)
		{
			free(buf);
			return (1);
		}
	ret = ft_read(fd, buf, &file[fd], line);
	free(buf);
	if (ret != 0 || file[fd] == NULL || file[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = file[fd];
	file[fd] = NULL;
	return (1);
}
