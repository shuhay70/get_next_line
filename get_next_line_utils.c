/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:17:17 by hshuhei           #+#    #+#             */
/*   Updated: 2025/12/08 17:31:33 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (s[s_len] == (char)c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	return (0);
}

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	strlen;

	i = 0;
	strlen = 0;
	while (src[strlen])
		strlen++;
	if (size == 0)
		return (strlen);
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlen);
}

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*ptr;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	ptr = malloc(s_len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < s_len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char    *new_str;
    size_t  len1;
    size_t  len2;
    size_t  i;
    size_t  j;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    if (!new_str)
    {
        free(s1); 
        return (NULL);
    }
    i = 0;
    while (i < len1)
    {
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < len2)
    {
        new_str[i + j] = s2[j];
        j++;
    }
    new_str[i + j] = '\0';
    free(s1);
    return (new_str);
}
