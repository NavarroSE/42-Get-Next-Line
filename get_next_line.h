/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manavarr <manavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:39:46 by manavarr          #+#    #+#             */
/*   Updated: 2022/11/28 19:39:46 by manavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(void *dest, const void *src, unsigned long n);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);

void	*ft_calloc(size_t count, size_t size);
char	*ft_read(int fd, char *stash);
char	*ft_get_line(char *stash);
char	*ft_remove_line(char *stash);
char	*get_next_line(int fd);

#endif
