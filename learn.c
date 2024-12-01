// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   learn.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/03 19:41:18 by gueberso          #+#    #+#             */
// /*   Updated: 2024/11/13 16:28:27 by gueberso         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// // ssize_t	len_line(int fd,)

// int main(int ac, char **av)
// {
// 	// if (ac == 2)
// 	// {
// 		int	fd;
// 		ssize_t bytes;
// 		static char	buffer[BUFFER_SIZE + 1];	
// 		if (ac == 2)
// 			fd = open(av[1], O_RDONLY);
// 		else
// 			fd = 0;
			
		
// 		if (fd < 0 || fd > 1023 || read(fd, 0, 0) < 0)
// 			return (0);
// 		bytes = read(fd, buffer, BUFFER_SIZE + 1);
// 		while (bytes > 0)
// 		{
			
// 			printf("nb of bytes : %zu\n", bytes);
// 			// while (ft_strchr(&buffer, 10) != NULL)
// 			// {
					
// 			// }
// 			write(1, &buffer, BUFFER_SIZE + 1);
// 			//write(1, "\n", 1);
// 			bytes = read(fd, buffer, BUFFER_SIZE + 1);
			
// 		}
// 		close(fd);
// 	//}
// 	return (0);
// }
