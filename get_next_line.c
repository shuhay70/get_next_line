/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:04:55 by hshuhei           #+#    #+#             */
/*   Updated: 2025/12/13 14:14:08 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_stash(char *stash, int fd)
{
	char		*buf;
	int			bytes;
	char		*newline_ptr;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		if (stash)
		{
			newline_ptr = ft_strchr(stash, '\n');
			if (newline_ptr)
				break ;
		}
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		stash = gnl_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*find_char(char *stash, char **newline_ptr)
{
	char		*fc_line;
	size_t		len;

	*newline_ptr = ft_strchr(stash, '\n');
	if (*newline_ptr)
		len = *newline_ptr - stash + 1;
	else
		len = ft_strlen(stash);
	fc_line = malloc(sizeof(char) * (len + 1));
	if (!fc_line)
		return (NULL);
	ft_strlcpy (fc_line, stash, len + 1);
	return (fc_line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*newline_ptr;
	char		*line;
	char		*next_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(stash, fd);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = find_char(stash, &newline_ptr);
	next_stash = NULL;
	if (newline_ptr)
		next_stash = ft_strdup(newline_ptr + 1);
	free(stash);
	stash = next_stash;
	return (line);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int     fd;
//     char    *line;

//     fd = open("gnl.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Error: Could not open file\n");
//         return (1);
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line); 
//     }
//     close(fd);
//     return (0);
// }
