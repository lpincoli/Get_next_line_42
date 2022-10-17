/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:33:16 by lpincoli          #+#    #+#             */
/*   Updated: 2022/10/16 16:34:56 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buf(int fd, char **fub)
{
	char		*buf;
	char		*print;
	char		*tmp;
	int			k;

	k = 1;
	buf = malloc(BUFFER_SIZE * (sizeof(char)));
	if (!buf)
		return (NULL);
	while (k > 0)
	{
		k = read(fd, buf, BUFFER_SIZE);
		if (!buf)
		{
			free(buf);
			return (NULL);
		}
		buf[k] = '\0';
		tmp = ft_strdup(*fub);
		*fub = ft_strjoin(tmp, buf);
		if (!fub)
			free(*fub);
		if (ft_strchr(*fub, '\n'))
		{
			print = get_print(fub);
			*fub = get_line(fub);
			return (print);
		}
	}
	return (NULL);
}

char	*get_print(char **fub)
{
	int			i;
	int			k;
	char		*print;
	char		*tmp;

	i = 0;
	k = 0;
	tmp = *fub;
	while ((tmp[i]) && (tmp[i] != '\n'))
		i++;
	print = malloc((i + 2) * sizeof(char));
	while (k <= i)
	{
		print[k] = tmp[k];
		k++;
	}
	print[k] = '\0';
	return (print);
}

char	*get_line(char **fub)
{
	int			i;
	int			l;
	int			k;
	char		*line;
	char		*tmp;

	i = 0;
	k = 0;
	tmp = *fub;
	while (tmp[i])
		i++;
	while (tmp[l] && tmp[l] != '\n')
		l++;
	l++;
	line = malloc(sizeof(char) * ((i - l) + 1));
	while (l < i)
	{
		line[k] = tmp[l];
		l++;
		k++;
	}
	line[k] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{	
	static char	*fub;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = get_buf(fd, &fub);
	return (buf);
}
