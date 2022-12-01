#include "slide_line.h"

int slide_line(int *line, size_t size, int direction) {
	size_t i;

	if (direction == SLIDE_LEFT) {
		slide_left(line, size);
		for (i = 1; i < size; i++)
		{
			if (line[i] == line[i - 1] && line[i] != 0)
			{
				line[i - 1] = line[i] + line[i];
				line[i] = 0;
			}
		}
		slide_left(line, size);
	} else {
		slide_right(line, size);
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] == line[i - 1] && line[i] != 0)
			{
				line[i] = line[i] + line[i];
				line[i - 1] = 0;
			}
		}
		slide_right(line, size);
	}
	return 1;
}

void slide_left(int *line, size_t size) {
	size_t i;

	for (i = 1; i < size; i++)
		{
			while (line[i] != 0 && line[i - 1] == 0)
				{
					line[i - 1] = line[i];
					line[i] = 0;
					i -= 1;
				}
		}
}

void slide_right(int *line, size_t size) {
	size_t i;

	for (i = 0; i < size - 1; i++)
		{
			if (line[i] != 0 && line[i + 1] == 0)
			{
				while (line[i] != 0 && line[i + 1] == 0)
				{
					line[i + 1] = line[i];
					line[i] = 0;
					i += 1;
				}
			i = 0;
			}
		}
}