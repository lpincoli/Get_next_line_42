
#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd;

	fd = open("testo_prova.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open the file");
		exit (1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
