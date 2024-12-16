
#include <stdio.h>
#include <fcntl.h>
int main() {
	
	int		fd = 0;		// file descriptor to read
	char	*buffer = NULL;
	int 	count;


	count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	buffer = get_next_line(fd);
	while ((buffer != NULL) && (buffer[0] != '\0'))
	{
		printf("%s", buffer);
		if (buffer)
			free(buffer);
		buffer = get_next_line(fd);
		count++;
	}
	close(fd);
	if (buffer)
		free(buffer);
	return (0);
}

