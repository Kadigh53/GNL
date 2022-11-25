/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:57:32 by aaoutem-          #+#    #+#             */
/*   Updated: 2022/11/24 18:20:55 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_index(char *p)
{
	int	i;

	i = 0;
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
	str = malloc(Buffer_size + 1);
	if (!p)
		p = ft_strdup("");
	while (!a_newline(p) && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		str[i] = '\0';
		p = ft_strjoin(p, str);
	}
	free(str);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*tmp;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	p = read_line(fd, BUFFER_SIZE, p);
	i = get_line_index(p);
	line = ft_substr(p, 0, i);
	tmp = ft_substr(p, i, ft_strlen(p) - i);
	free(p);
	p = tmp;
	return (line);
}

/*int main()
{
	int fd= open("lebFile.txt", O_RDWR);
	// int i=0;
	// while (i < 1)
	// {
	// 	printf("%s", get_next_line(fd));
	// 	i++;
	// }
	printf("%s", get_next_line(fd));
}*/
