/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:17:17 by hshuhei           #+#    #+#             */
/*   Updated: 2025/12/13 14:15:54 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size);
char			*ft_strdup(const char *s);
char			*gnl_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);

#endif