/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:06:06 by aaoutem-          #+#    #+#             */
/*   Updated: 2022/11/26 11:06:09 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
int		a_newline(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef FDMAX
#  define FDMAX 10240
# endif

# ifndef FDF
#  define FDF 10241
# endif

#endif
