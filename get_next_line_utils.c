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

char	*ft_strchr(char *s, int c)
{
	char	*pt;

	pt = (char *) s;
	while (*pt != 0)
	{
		if (*pt == c)
			return (pt);
		pt++;
	}
	if (*pt == c)
		return (pt);
	return (0);
}

char	*ft_freejoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	str = calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(*str));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[i] = s2[i];
		i++;
	}
	ft_free_fub(&s1);
	ft_free_fub(&s2);
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return ("");
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			count;
	void			*p;
	unsigned char	*p2;

	if (size == 0 || nmemb == 0)
	{
		size = 1;
		nmemb = 1;
	}
	count = nmemb * size;
	p = malloc(count);
	if (!p)
		return (NULL);
	p2 = (unsigned char *)p;
	while (count != 0)
	{
		*p2 = '\0';
		p2++;
		count--;
	}
	return (p);
}
