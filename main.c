/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:39:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/30 20:45:12 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int		fd = 0;
// 	char	*line;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <file>\n", argv[0]);
// 		return (1);
// 	}
	
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	int	i = 1;
// 	while (i < argc)
// 	{
// 		fd = open(argv[i], O_RDONLY);
// 		while ((line = get_next_line(fd)) != NULL)
// 		{
// 			printf("|-%s-|", line);
// 			free(line);
// 		}
// 		printf("%s\n", get_next_line(fd));
// 		close(fd);
// 		i++;
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <file>\n", argv[0]);
// 		return (1);
// 	}

	
// 	(void) argc;
// 	(void) argv;
// 	fd = open(0, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		line = get_next_line(0);
// 		printf("|-%s-|", line);
// 		free(line);
// 		i++;
// 	}
// 	while ((line = get_next_line(0)) != NULL)
// 	{
// 		printf("|-%s-|", line);
// 		free(line);
// 	}
// 	close(0);
// 	return (0);

	
// }


// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;
// 	static char	buffer[FOPEN_MAX + 1][BUFFER_SIZE + 1]; // pourquoi + 1 ?
// 	static int	i = 1;
	
// 	if (ac == 2)
// 		fd= open(av[1], O_RDONLY);
// 	while (i < ac - 1)
// 	{
		
// 	}
	
	
	
// }


int main() 
{
    int fd = open("text.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) 
	{
        printf("%s", line);
        free(line);
		sleep(1);
    }

    close(fd);
    return (0);
}
