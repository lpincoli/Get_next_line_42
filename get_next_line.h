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
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_buf(int fd, char **fub);
char	*ft_strchr(char *s, int c);
char	*ft_freejoin(char *s1, char *s2);
char	*get_print(char **fub);
char	*get_line(char **fub);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_fub(char **fub);
#endif /* GET_NEXT_LINE_H */
