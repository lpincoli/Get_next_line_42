/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:42:28 by lpincoli          #+#    #+#             */
/*   Updated: 2022/10/16 16:47:47 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strddown(char *dest, char *src)
{
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	free(dest);
	dest = (char *)malloc(sizeof(char) * ft_lena(src, '\0') + 2);
	while (src[i] != '\0' && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

int	ft_presente_bybianca(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (c == 0)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_freejoin(char *s1, char *s2)
{
	char	*str;
	int	i;
	int	k;
	
	if (!s1)
	{
		free(s1);
		s1 = ft_calloc(1,sizeof(char));
	}
	str = ft_calloc(ft_lena(s1, '\0') + ft_lena(s2, '\0') + 1, 1);
	if (!s2)
	{
		free (s1);
		free (str);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	k = -1;
	while (s2[++k])
		str[i + k] = s2[k];
	str[i + k] = '\0';
	s1 = ft_strdup(s1, str);
	return (s1);
}

size_t	ft_lena(char *str, int c)
{
	int	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strdup(char *dest, char *src)
{
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	free(dest);
	dest = ft_calloc(ft_lena(src, '\0') + 1, sizeof(char));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	char	*p2;

	p2 = malloc(nmemb * size);
	if (p2 == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p2[i] = '\0';
		i++;
	}
	return (p2);
}
