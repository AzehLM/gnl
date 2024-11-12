/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:41:25 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/03 20:10:03 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# define BUFFER_SIZE 4096

size_t	ft_strlen(char *str);

char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
