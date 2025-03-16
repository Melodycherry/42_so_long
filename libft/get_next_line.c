// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/12 17:31:29 by mlaffita          #+#    #+#             */
// /*   Updated: 2025/03/16 15:36:51 by mlaffita         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "libft.h"

// char	*gnl_strchr(const char *str, int c)
// {
// 	int		i;
// 	char	*found_str;
// 	char	char_c;

// 	i = 0;
// 	char_c = (char) c;
// 	found_str = (char *)str;
// 	while (str[i])
// 	{
// 		if (str[i] == char_c)
// 			return (&found_str[i]);
// 		i++;
// 	}
// 	if (str[i] == char_c)
// 		return (&found_str[i]);
// 	return (0);
// }

// char	*gnl_strjoin(char *s1, char const *s2)
// {
// 	char	*s_out;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1)
// 		s1 = "";
// 	if (!s2)
// 		s2 = "";
// 	s_out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
// 	if (!s_out)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	while (s1[++i])
// 		s_out[i] = s1[i];
// 	while (s2[j])
// 		s_out[i++] = s2[j++];
// 	s_out[i] = '\0';
// 	return (s_out);
// }

// char	*gnl_strndup(const char *src, size_t n)
// {
// 	char	*dest;
// 	size_t	length;
// 	size_t	i;

// 	length = ft_strlen(src);
// 	i = 0;
// 	if (length > n)
// 		length = n;
// 	dest = (char *)malloc(sizeof(char) * (length + 1));
// 	if (dest == NULL)
// 		return (NULL);
// 	while (i < length)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[length] = '\0';
// 	return (dest);
// }

// char	*gnl_strdup(const char *s1)
// {
// 	char	*dest;
// 	size_t	i;

// 	dest = (char *) malloc(ft_strlen(s1) + 1);
// 	if (!dest)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	dest[i] = 0;
// 	return (dest);
// }

// t_fd	*ft_init(void)
// {
// 	t_fd	*file_d;

// 	file_d = malloc(sizeof(t_fd));
// 	if (!file_d)
// 		return (NULL);
// 	file_d->chunk = NULL;
// 	file_d->line = NULL;
// 	file_d->totrim = NULL;
// 	file_d->nl = NULL;
// 	return (file_d);
// }

// void	ft_lastlineisnull(t_fd *file_d)
// {
// 	if (*file_d->chunk == '\0')
// 	{
// 		free(file_d->chunk);
// 		file_d->chunk = NULL;
// 	}
// }

// char	*extract_chunk(int fd, t_fd	*file_d)
// {
// 	ssize_t	bytesread;
// 	char	*temp;

// 	while (1)
// 	{
// 		bytesread = read(fd, file_d->buffer, BUFFER_SIZE);
// 		if (bytesread == -1 || bytesread == 0)
// 		{
// 			if (bytesread == 0 && file_d->chunk)
// 			{
// 				ft_lastlineisnull(file_d);
// 				return (file_d->chunk);
// 			}
// 			free(file_d->chunk);
// 			return (NULL);
// 		}
// 		file_d->buffer[bytesread] = '\0';
// 		temp = gnl_strjoin(file_d->chunk, file_d->buffer);
// 		free(file_d->chunk);
// 		file_d->chunk = temp;
// 		if (gnl_strchr(file_d->buffer, '\n') != 0)
// 			break ;
// 	}
// 	return (file_d->chunk);
// }

// char	*extract_line(int fd, t_fd	*file_d)
// {
// 	size_t	linelen;

// 	file_d->chunk = extract_chunk(fd, file_d);
// 	if (!file_d->chunk)
// 		return (NULL);
// 	file_d->nl = gnl_strchr(file_d->chunk, '\n');
// 	if (file_d->nl)
// 	{
// 		linelen = ft_strlen(file_d->chunk) - ft_strlen(file_d->nl) + 1;
// 		file_d->line = gnl_strndup(file_d->chunk, linelen);
// 		file_d->totrim = file_d->chunk;
// 		file_d->chunk = gnl_strdup(file_d->nl + 1);
// 		free(file_d->totrim);
// 	}
// 	else
// 	{
// 		file_d->line = gnl_strdup(file_d->chunk);
// 		free(file_d->chunk);
// 		file_d->chunk = NULL;
// 	}
// 	return (file_d->line);
// }

// char	*get_next_line(int fd)
// {
// 	static t_fd	*file_d;

// 	if (!file_d)
// 		file_d = ft_init();
// 	file_d->line = extract_line(fd, file_d);
// 	if (!file_d->line && file_d)
// 	{
// 		free(file_d);
// 		file_d = NULL;
// 		return (NULL);
// 	}
// 	return (file_d->line);
// }


#include "libft.h"

char	*ft_free(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (NULL);
}

int	read_to_buffer(int fd, char *buffer)
{
	int	rd;

	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd >= 0)
		buffer[rd] = '\0';
	return (rd);
}

int	update_line(char *buffer, char **line)
{
	char	*n_buff;

	n_buff = ft_strchr(buffer, '\n');
	if (n_buff)
	{
		*n_buff = '\0';
		*line = ft_strjoin_free(*line, buffer);
		if (!*line)
			return (0);
		*line = ft_strjoin_free(*line, "\n");
		if (!*line)
			return (0);
		ft_strlcpy(buffer, n_buff + 1, BUFFER_SIZE - (n_buff - buffer));
		return (1);
	}
	*line = ft_strjoin_free(*line, buffer);
	if (!*line)
		return (0);
	*buffer = '\0';
	return (0);
}

int	handle_end_of_file(int rd, char *buffer, char **line)
{
	if (rd == GNL_ERROR)
		return (0);
	if (rd == GNL_EOF && (!*line || **line == '\0') && buffer[0] == '\0')
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			rd;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer[0] == '\0')
		{
			rd = read_to_buffer(fd, buffer);
			if (!handle_end_of_file(rd, buffer, &line))
				return (ft_free(&line));
		}
		if (update_line(buffer, &line))
			return (line);
		if (rd == GNL_EOF)
			break ;
	}
	return (line);
}
