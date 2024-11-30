/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:41:25 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/30 17:53:11 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> //read
# include <stdlib.h> // malloc - free
# include <stdio.h> // FOPEN_MAX

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD FOPEN_MAX
# endif

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
