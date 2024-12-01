/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:39:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/01 20:03:10 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd[ac - 1];
	char	*lines[ac - 1];
	int		files_left;
	int		i;

	if (ac == 1)
	{
		char	*line_std;

		printf("CTRL+D pour terminer (CTRL+F kill the program):\n");
		while ((line_std = get_next_line(0)) != NULL)
		{
			printf("%s", line_std);
			free(line_std);
		}
		return (0);
	}
	files_left = 0;
	for (i = 1; i < ac; i++)
	{
		fd[i - 1] = open(av[i], O_RDONLY);
		if (fd[i - 1] == -1)
		{
			//perror(av[i]);
			lines[i - 1] = NULL;
		}
		else
		{
			files_left++;
			lines[i - 1] = get_next_line(fd[i - 1]);
		}
	}
	while (files_left > 0)
	{
		for (i = 0; i < ac - 1; i++)
		{
			if (lines[i])
			{
				printf("File %s: %s", av[i + 1], lines[i]);
				free(lines[i]);
				lines[i] = get_next_line(fd[i]);
				if (!lines[i])
				{
					close(fd[i]);
					files_left--;
				}
			}
		}
	}
	return (0);
}

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
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		fd = open(argv[i], O_RDONLY);
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(0);
// 	return (0);
// }
