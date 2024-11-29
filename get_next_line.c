/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:15:14 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/27 13:47:16 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static	char	buffer[MAX_FD][BUFFER_SIZE];

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 )
		return (NULL);
	
}



// static char *BUFFER[][]
