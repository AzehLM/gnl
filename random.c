// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   random.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/27 15:39:42 by gueberso          #+#    #+#             */
// /*   Updated: 2024/11/29 15:18:45 by gueberso         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// #include <fcntl.h>
// #include <stdio.h>

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
