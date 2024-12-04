/*--------------------#
# Advent of code 2024 #
# Dia 4, ejercicio 1  #
#---------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 150

static void	find(char matriz[MAX_LINE_LENGTH][MAX_LINE_LENGTH], int *total)
{
	for(int x = 0; x < MAX_LINE_LENGTH; x++)
	{
		for(int y = 0; y < MAX_LINE_LENGTH; y++)
		{
			if (matriz[x][y] == 'X')
			{
				if ((matriz[x][y+1] == 'M') && (matriz[x][y+2] == 'A') 
				&& (matriz[x][y+3] == 'S')) // Hor
					*total += 1;
				if ((matriz[x][y-1] == 'M') && (matriz[x][y-2] == 'A') 
				&& (matriz[x][y-3] == 'S')) // Hor inv
					*total += 1;
				if ((matriz[x+1][y] == 'M') && (matriz[x+2][y] == 'A') 
				&& (matriz[x+3][y] == 'S')) // vert 
					*total += 1;
				if ((matriz[x-1][y] == 'M') && (matriz[x-2][y] == 'A') 
				&& (matriz[x-3][y] == 'S')) // vert inv
					*total += 1;
				if ((matriz[x-1][y-1] == 'M') && (matriz[x-2][y-2] == 'A') 
				&& (matriz[x-3][y-3] == 'S')) // diag lu
					*total += 1;
				if ((matriz[x+1][y-1] == 'M') && (matriz[x+2][y-2] == 'A') 
				&& (matriz[x+3][y-3] == 'S')) // diag ld
					*total += 1;
				if ((matriz[x-1][y+1] == 'M') && (matriz[x-2][y+2] == 'A') 
				&& (matriz[x-3][y+3] == 'S')) // diag ru
					*total += 1;
				if ((matriz[x+1][y+1] == 'M') && (matriz[x+2][y+2] == 'A') 
				&& (matriz[x+3][y+3] == 'S')) // diag rd
					*total += 1;
			}
		}
	}
}

int main(int argc, char **argv)
{
	FILE	*file;
	char	buffer[MAX_LINE_LENGTH][MAX_LINE_LENGTH];
    int     i;
    int		total;

	(void)argc;
	if (!argv[1])
	{
		fprintf(stderr, "You must input a file as an argument.");
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error opening text file");
		exit(1);
	}
    i = 0;
    while (fgets(buffer[i], MAX_LINE_LENGTH, file) != 0)
        i++;
    fclose(file);
	total = 0;
	i = 0;
	find(buffer, &total);
	printf("%d", total);
    return (0);
}