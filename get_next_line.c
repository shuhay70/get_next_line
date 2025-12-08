/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:04:55 by hshuhei           #+#    #+#             */
/*   Updated: 2025/12/07 17:50:33 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*newline_ptr;
	int			bytes;
	size_t		len;

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
	len = newline_ptr ? (newline_ptr - stash + 1) : ft_strlen(stash);
}
