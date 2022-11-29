/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:05:59 by aaoutem-          #+#    #+#             */
/*   Updated: 2022/11/26 11:06:01 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_line_index(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
	{
		if (p[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

int	a_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, int Buffer_size, char *p)
{
	char	*str;
	int		i;

	i = 1;
	if (!p)
		p = ft_strdup("");
	str = malloc(Buffer_size + 1);
	if (!str)
		return (NULL);
	while (!a_newline(p) && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			free(p);
			return (NULL);
		}
		str[i] = '\0';
		p = ft_strjoin(p, str);
	}
	free(str);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p[FDF];
	char		*tmp;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FDMAX)
		return (NULL);
	i = 0;
	p[fd] = read_line(fd, BUFFER_SIZE, p[fd]);
	i = get_line_index(p[fd]);
	line = ft_substr(p[fd], 0, i);
	tmp = ft_substr(p[fd], i, ft_strlen(p[fd]) - i);
	free(p[fd]);
	p[fd] = tmp;
	return (line);
}

int main()
{
	int f1= open("f1.txt",O_RDONLY);
	printf("%s",get_next_line(f1));
	int f2= open("f2.txt",O_RDONLY);
	printf("%s",get_next_line(f2));
	int f3= open("f3.txt",O_RDONLY);
	printf("%s",get_next_line(f3));
	int f4= open("f4.txt",O_RDONLY);
	printf("%s",get_next_line(f4));
	printf("%s",get_next_line(f1));
}