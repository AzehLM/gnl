/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:39:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/01 10:38:35 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd = 0;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	int	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("|-%s-|", line);
			free(line);
		}
		printf("%s\n", get_next_line(fd));
		close(fd);
		i++;
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


// int main()
// {
//     int fd = open("text.txt", O_RDONLY);
//     char *line;

//     while ((line = get_next_line(fd)) != NULL)
// 	{
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }

int main(int argc, char **argv)
{
    int     fd1, fd2;
    char    *line1, *line2;
    int     count1 = 0, count2 = 0;

    // Vérifier si des fichiers sont fournis en argument
    if (argc < 3)
    {
        printf("Usage: %s file1 file2 file3\n", argv[0]);
        return 1;
    }

    // Ouvrir les fichiers
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);


    if (fd1 == -1 || fd2 == -1)
    {
        perror("Erreur d'ouverture de fichier");
        return 1;
    }

    // Lire et afficher les lignes de chaque fichier en alternance
    while (1)
    {
        // Fichier 1
        line1 = get_next_line(fd1);
        if (line1)
        {
            printf("File1 (Line %d): %s", ++count1, line1);
            free(line1);
        }

        // Fichier 2
        line2 = get_next_line(fd2);
        if (line2)
        {
            printf("File2 (Line %d): %s", ++count2, line2);
            free(line2);
        }

        // Vérifier si tous les fichiers sont terminés
        if (!line1 && !line2)
            break;
    }

    // Fermer les fichiers
    close(fd1);
    close(fd2);

    printf("\nLignes lues : Fichier 1 = %d, Fichier 2 = %d\n", count1, count2);

    return 0;
}
