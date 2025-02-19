//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "read.h"

int load(rgb ***image, int ***matrix, int *width, int *length,
		 int *max, int *type, char *typevar, int *x2, int *y2)
{
	char filetoread[20];
	scanf("%s", filetoread);
	static int ok;
	int multi = 0, single = 0, n, m, maxvalue;
	if (ok == 0) {
		FILE *in = fopen(filetoread, "rb");
		if (!in) {
			printf("Failed to load %s\n", filetoread);
			if (*type == 1)
				free_function_matrix(*length, &matrix);
			if (*type == 2) {
				free_function_image(*length, &image);
			}
			*type = 0;
			return 1;
		} //in functie de tipul citit apelam o functie pentru citire
		fscanf(in, "%s", typevar), fscanf(in, "%d%d%d", &n, &m, &maxvalue);
		if (strcmp(typevar, "P2") == 0) {
			*matrix = read_P2(in, n, m, maxvalue), multi = 0, single = 1;
		} //multi si single ne ajuta pentru pastrarea tipului matricei citite
		if (strcmp(typevar, "P3") == 0) {
			*image = read_P3(in, n, m, maxvalue), multi = 1, single = 0;
		}
		if (strcmp(typevar, "P5") == 0) {
			*matrix = read_P5(in, n, m, maxvalue), multi = 0, single = 1;
		}
		if (strcmp(typevar, "P6") == 0) {
			*image = read_P6(in, n, m, maxvalue), multi = 1, single = 0;
		}
		fclose(in), ok = 1, *width = n, *length = m, *max = maxvalue;
		if (multi == 1) {
			*type = 2; // salvam tipul matricei
		} else {
			*type = 1;
		}
		printf("Loaded %s\n", filetoread), *x2 = n, *y2 = m;
	} else { //in caz ca a fost reapelat save-ul dam free matricei existente
		FILE *in = fopen(filetoread, "rb");
		if (!in) {
			printf("Failed to load %s\n", filetoread);
			if (*type == 1) {
				free_function_matrix(*length, &matrix);
			}
			if (*type == 2) {
				free_function_image(*length, &image);
			}
			*type = 0;
			return 1;
		}
		if (*type == 1) {
			free_function_matrix(*length, &matrix);
		} else if (*type == 2) {
			free_function_image(*length, &image);
		}
		fscanf(in, "%s", typevar), fscanf(in, "%d%d%d", &n, &m, &maxvalue);
		if (strcmp(typevar, "P2") == 0) {
			*matrix = read_P2(in, n, m, maxvalue), multi = 0, single = 1;
		}
		if (strcmp(typevar, "P3") == 0) {
			*image = read_P3(in, n, m, maxvalue), multi = 1, single = 0;
		}
		if (strcmp(typevar, "P5") == 0) {
			*matrix = read_P5(in, n, m, maxvalue), multi = 0, single = 1;
		}
		if (strcmp(typevar, "P6") == 0) {
			*image = read_P6(in, n, m, maxvalue), multi = 1, single = 0;
		}
		*width = n, *length = m, *max = maxvalue;
		if (multi == 1 && single == 0) {
			*type = 2;
		} else { // salvam tipul matricei
			*type = 1;
		}
		fclose(in), *x2 = n, *y2 = m, printf("Loaded %s\n", filetoread);
	}
	return 0;
}

void free_function_matrix(int dim, int ****matrix)
{
	for (int i = 0; i < dim; i++)
		free((**matrix)[i]);
	free(**matrix);
}

void free_function_image(int dim, rgb ****image)
{
	for (int i = 0; i < dim; i++)
		free((**image)[i]);
	free(**image);
}
