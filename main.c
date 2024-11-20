#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
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

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	
	(void) argc;
	(void) argv;
	fd = open(0, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	int i = 0;
	while (i < 3)
	{
		line = get_next_line(0);
		printf("|-%s-|", line);
		free(line);
		i++;
	}
	while ((line = get_next_line(0)) != NULL)
	{
		printf("|-%s-|", line);
		free(line);
	}
	close(0);
	return (0);

	
}
