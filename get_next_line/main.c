#include <stdio.h>
void fun()
{
	system("leaks a.out");
}
int main()
{
	atexit(fun);
	int fd = open("ahmed.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}