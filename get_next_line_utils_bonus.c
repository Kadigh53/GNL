/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:06:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2022/11/26 11:06:26 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	j;
	size_t			k;

	j = 0;
	k = ft_strlen(s) - start + 1;
	if (len < (size_t)(ft_strlen(s) - start))
		k = len + 1;
	if (start < (size_t)ft_strlen(s) && *s != 0)
	{
		p = malloc(k * sizeof(char));
		if (!p)
			return (NULL);
		while ((s + start)[j] && j < len)
		{
			p[j] = (s + start)[j];
			j++;
		}
		p[j] = '\0';
		return (p);
	}
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		ft_memcpy(p, s1, ft_strlen(s1) * sizeof(char));
		ft_memcpy(p + ft_strlen(s1), s2, ft_strlen(s2) * sizeof(char));
		p[i] = '\0';
		free(s1);
		return (p);
	}
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*p;
	int		len;

	i = 0;
	len = ft_strlen(s1) + 1;
	p = (char *)malloc(len * sizeof(char));
	if (!p)
		return (NULL );
	else
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
}
