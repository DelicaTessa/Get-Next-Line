/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 11:06:09 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/16 11:26:52 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		counter;
	char	*new;

	index = 0;
	counter = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[index] != '\0')
	{
		new[index] = s1[index];
		index++;
	}
	while (s2[counter] != '\0')
	{
		new[index + counter] = s2[counter];
		counter++;
	}
	new[index + counter] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != (char)c)
	{
		if (s[index] == '\0')
			return (NULL);
		index++;
	}
	return ((char *)s + index);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		index;

	index = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_remainder(char *str, int start)
{
	int	index;

	index = 0;
	while (str[index + start])
	{
		str[index] = str[index + start];
		index++;
	}
	str[index] = '\0';
	return (str);
}
