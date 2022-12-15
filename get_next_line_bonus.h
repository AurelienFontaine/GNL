/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:03:05 by afontain          #+#    #+#             */
/*   Updated: 2022/12/13 13:24:45 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdint.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
void	read_next_line(char *line, char *buffer);
char	*line_to_buffer(char *str);
char	*read_line(int fd, char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *str1, char *str2);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif