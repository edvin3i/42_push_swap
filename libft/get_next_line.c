/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:18:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/06 22:59:10 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

char	*ft_get_new_chars(int fd, char *saved_lines, char *buffer)
{
	int	chars_counter;

	if (!buffer)
		return (NULL);
	chars_counter = 1;
	while (!ft_strchr(saved_lines, '\n') && chars_counter != 0)
	{
		chars_counter = read(fd, buffer, BUFFER_SIZE);
		if (chars_counter == -1)
			return (NULL);
		buffer[chars_counter] = '\0';
		saved_lines = ft_strjoin(saved_lines, buffer);
	}
	return (saved_lines);
}

char	*ft_get_line(char *saved_line)
{
	size_t		i;
	char		*line;

	i = 0;
	if (!saved_line)
		return (NULL);
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char ) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
	{
		line[i] = saved_line[i];
		i++;
	}
	if (saved_line[i] == '\n')
	{
		line[i] = saved_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *saved_line)
{
	int		i;
	int		j;
	size_t	new_line_len;
	char	*new_line;

	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	if (!saved_line[i])
	{
		free(saved_line);
		return (NULL);
	}
	new_line_len = ft_strlen(saved_line) - i + 1;
	new_line = (char *) malloc(sizeof(char) * new_line_len);
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (saved_line[i])
		new_line[j++] = saved_line[i++];
	new_line[j] = '\0';
	free(saved_line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	static char	*saved_lines;

	if (read(fd, buff, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved_lines)
	{
		saved_lines = (char *)malloc(sizeof (char) * 1);
		if (!saved_lines)
			return (NULL);
		saved_lines[0] = '\0';
	}
	saved_lines = ft_get_new_chars(fd, saved_lines, buff);
	if (!saved_lines)
		return (NULL);
	line = ft_get_line(saved_lines);
	saved_lines = ft_save(saved_lines);
	if (line[0])
		return (line);
	free(line);
	return (NULL);
}
