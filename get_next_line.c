/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 12:10:49 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/16 12:22:06 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_error(char **str)
{
	if (*str != NULL)
		free(*str);
	*str = NULL;
	return (-1);
}

static int	ft_eof(char **line, char **str)
{
	*line = ft_strdup("");
	if (*str != NULL)
		free(*str);
	*str = NULL;
	return (0);
}

static int	ft_make_line(char **line, char **str)
{
	int		index;
	int		counter;
	int		res;
	char	*remain;

	index = 0;
	counter = 0;
	while ((*str)[index] != '\0' && (*str)[index] != '\n')
		index++;
	*line = (char *)malloc(sizeof(char) * (index + 1));
	if (*line == NULL)
		return (ft_error(str));
	while (counter < index)
	{
		(*line)[counter] = (*str)[counter];
		counter++;
	}
	(*line)[counter] = '\0';
	res = (((*str)[index] == '\n') ? 1 : 0);
	remain = (res == 1 ? ft_remainder(*str, index + 1) : NULL);
	if (res == 0 && *str != NULL)
		free(*str);
	*str = remain;
	return (res);
}

static int	gnl_loop(int fd, char **line, char **str)
{
	ssize_t rd;
	char	buffer[BUF_SIZE + 1];
	char	*temp;

	rd = 1;
	while (!(ft_strchr(str[fd], '\n')) && (rd > 0))
	{
		rd = read(fd, buffer, BUF_SIZE);
		if (rd < 0)
			return (ft_error(&str[fd]));
		if (rd == 0 && str[fd][0] == '\0')
			return (ft_eof(line, &str[fd]));
		buffer[rd] = '\0';
		temp = ft_strjoin(str[fd], buffer);
		if (temp == NULL)
			return (ft_error(&str[fd]));
		if (str[fd] != NULL)
			free(str[fd]);
		str[fd] = temp;
	}
	return (ft_make_line(line, &str[fd]));
}

int			get_next_line(int fd, char **line)
{
	static char *str[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || !line || BUF_SIZE <= 0)
		return (-1);
	if (str[fd] == NULL)
	{
		str[fd] = ft_strdup("");
		if (str[fd] == NULL)
			return (-1);
	}
	return (gnl_loop(fd, line, str));
}
