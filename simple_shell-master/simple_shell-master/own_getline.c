#include "main.h"
/**
 * custom_getline - custom implementation of getline
 * @lineptr: pointer to the line buffer
 * @n: pointer to the size of the line buffer
 * Return: number of characters read, or -1 on error
 */
ssize_t custom_getline(char **lineptr, size_t *n)
{
	ssize_t read_chars = 0;
	size_t total_chars = 0;
	char *line, *new_line;
	char c;

	line = *lineptr;
	while (1)
	{
		read_chars = read(STDIN_FILENO, &c, 1);
		if (read_chars == -1)
		{
			if (total_chars == 0)
				return (-1); /*Read errror*/
		}
		if (read_chars == 0)
			break; /* End of input*/
		if (c == '\n')
		{
			line[total_chars] = '\0';
			break;
		}
		line[total_chars] = c;
		total_chars++;
		if (total_chars >= *n - 1)
		{
			*n *= 2;
			new_line = realloc(line, *n);
			if (new_line == NULL)
				return (-1); /*Allocation error*/
		line = new_line;
		*lineptr = line;
		}
	}
	return (total_chars);
}
