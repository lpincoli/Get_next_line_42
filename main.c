
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
	char	*str;
	for(int i = 0; i < 7; i++)
	{
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	}
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
}
/*if (ft_strchr(buf, '\0'))
		{
			tmp = ft_strdup(*fub);
			ft_free_fub(fub);
			*fub = ft_freejoin(tmp, buf);
			tmp = get_print(fub);
			return (tmp);
		}*/
