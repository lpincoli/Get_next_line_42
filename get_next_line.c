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

void	ft_free_fub(char **fub)
{
	if (*fub != NULL || fub)
	{
		free(*fub);
		fub = NULL;
	}
}

char	*get_buf(int fd, char **fub)
{
	char		*buf;
	char		*tmp;
	int			k;

	k = 1;
	while (k > 0)
	{
		buf = (char *)calloc((BUFFER_SIZE + 1), (sizeof(*buf)));
		k = read(fd, buf, BUFFER_SIZE);
		if (!buf)
		{
			free(buf);
			return (NULL);
		}
		if (ft_strchr(buf, '\0'))
		{
			tmp = ft_strdup(*fub);
			ft_free_fub(fub);
			*fub = ft_freejoin(tmp, buf);
			tmp = get_print(fub);
			return (tmp);
		}
		tmp = ft_strdup(*fub);
		ft_free_fub(fub);
		*fub = ft_freejoin(tmp, buf);
		if (!fub)
			free(*fub);
		if (ft_strchr(*fub, '\n'))
		{
			tmp = get_print(fub);
			*fub = get_line(fub);
			return (tmp);
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
	print = (char *)malloc((i + 2) * sizeof(char));
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
	l = 0;
	tmp = *fub;
	while (tmp[i])
		i++;
	while (tmp[l] && tmp[l] != '\n')
		l++;
	l++;
	line = (char *)malloc(sizeof(char) * ((i - l) + 1));
	while (l < i)
	{
		line[k] = tmp[l];
		l++;
		k++;
	}
	line[k] = '\0';
	ft_free_fub(fub);
	return (line);
}

char	*get_next_line(int fd)
{	
	static char	*fub;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!fub)
		fub = calloc(BUFFER_SIZE + 1, sizeof(*fub));
	buf = get_buf(fd, &fub);
	/*if (!buf)
	{
		free(buf);
		return (NULL);
	}*/
	return (buf);
}
