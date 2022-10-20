/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:35:13 by lpincoli          #+#    #+#             */
/*   Updated: 2022/10/16 16:37:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*ft_strddown(char *dest, char *src);
char	*get_buf(int fd, int *check);
int	ft_presente_bybianca(const char *s, int c);
char	*ft_freejoin(char *s1, char *s2);
char	*get_print(char *fub);
char	*get_line(char *fub);
size_t	ft_lena(char *str, int c);
char	*ft_strdup(char *dest, char *src);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strcpy(char *dest, char *src);
#endif /* GET_NEXT_LINE_H */
