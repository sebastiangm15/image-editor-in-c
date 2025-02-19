//315CA-Gilma Sebastian Mihai
#pragma once
typedef struct {
	int x, y, z;
} rgb;

int load(rgb ***image, int ***matrix, int *width, int *length, int *max,
		 int *type, char *typevar, int *x2, int *y2);

void free_function_matrix(int dim, int ****matrix);

void free_function_image(int dim, rgb ****image);
