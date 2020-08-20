
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
 int fd = open("fewchar_perline.txt", O_RDONLY);
	int ret = 1;
 char *line = "";

	while(ret > 0)
	{
    	ret = get_next_line(fd, &line);
    	printf("[%d] %s\n", ret, line);
		free (line);
	}

return (0);
}	