/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:04:55 by hshuhei           #+#    #+#             */
/*   Updated: 2025/12/08 16:09:10 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*newline_ptr;
	int			bytes;
	char		*line;
	size_t		len;
	char		*next_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		if (stash && (newline_ptr = ft_strchr(stash, '\n')))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		stash = gnl_strjoin(stash, buf);
	}
	free(buf);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	newline_ptr = ft_strchr(stash, '\n');
	if (newline_ptr)
		len = newline_ptr - stash + 1;
	else
		len = ft_strlen(stash);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strlcpy (line, stash, len + 1);
	next_stash = NULL;
	if (newline_ptr)
		next_stash = ft_strdup(newline_ptr + 1);
	free(stash);
	stash = next_stash;
	return (line);
}

#include <fcntl.h>
int main(void)
{
	int     fd;
    char    *line;

    fd = open("gnl.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: Could not open file\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); 
    }
    close(fd);
    return (0);
}

