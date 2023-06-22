#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int read_trim_line(int file, char **line, unsigned int line_num)
{
	char *ptr, byte = ' ';
	ssize_t bytes_read;
	unsigned int index = 0, line_is_comment = 0;

	ptr = malloc(sizeof(*ptr) * 100);
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-2);
	}
	*line = ptr;
	while (byte != '\n' && index < 99)
	{
		bytes_read = read(file, &byte, 1);
		if (bytes_read == -1)
		{
			print_err("", line_num);
			return (-2);
		}
		if (bytes_read == 0)
			break;
		if (byte == '#' && index == 0 && !line_is_comment)
			line_is_comment = 1;
		if ((byte != ' ' || index) && byte != '\n' && !line_is_comment)
		{
			ptr[index] = byte;
			index++;
		}	
	}
	if (index == 0)
	{
		if (bytes_read == 0)
			return (EOF);
		ptr[index] = '\0';
		return (0);
	}
	ptr[index] = '\0';
	return (index);
}
