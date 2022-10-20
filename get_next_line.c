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

char	*get_buf(int fd, int *check)
{
	char		*buf;
	ssize_t	count;
	
	buf = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buf)
		return (NULL);
	count = read(fd, buf, BUFFER_SIZE);
	if (count <= 0)
	{
		*check = -1;
		free(buf);
		return (NULL);
	}
	buf[count] = '\0';
	*check = count;
	return (buf);
}

char	*get_line(char *fub)
{
	int			i;
	int			k;
	char		*line;

	i = 0;
	while (fub[i] && fub[i] != '\n')
		i++;
	if (!fub[i])
		return (NULL);
	line = ft_calloc(sizeof(char),(ft_lena(fub, '\0') - i));
	if (!line || line == NULL)
	{
		free(line);
		free(fub);
		return (NULL);
	}
	i++;
	k = 0;
	while (fub[i])
		line[k++] = fub[i++];
	line[k] = '\0';
	free(fub);
	return (line);
}

char	*get_next_line(int fd)
{	
	static char	*fub;
	char		*buf;
	char		*print;
	int			check;
	
	if (fd < 0 || fd > 1024|| BUFFER_SIZE <= 0)
		return (NULL);
	check = 1;
	while (ft_presente_bybianca(fub, check) == 0)
	{
		buf = get_buf(fd, &check);
		if (check == -1 && fub == NULL)
		{
			free(fub);
			return (NULL);
		}
		fub = ft_freejoin(fub, buf);
		free(buf);
	}
	print = ft_calloc(1, (ft_lena(fub, '\n') + 2));
	print = ft_strddown(print, fub);
	fub = get_line(fub);
	return (print);
}
