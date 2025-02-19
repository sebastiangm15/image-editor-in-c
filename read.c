#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "load.h"

int **read_P2(FILE *in, int n, int m, int maxvalue)
{
	int **matrix;
	matrix = (int **)malloc(m * sizeof(int *));
	if (!matrix) {
		fprintf(stderr, "malloc() failled");
		return NULL;
	}

	for (int i = 0; i < m; i++) {
		matrix[i] = (int *)malloc(n * sizeof(int));
		if (!matrix[i]) {
			for (int j = 0; j < i; j++)
				free(matrix[j]);
		}
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n ; j++) {
			fscanf(in, "%d", &matrix[i][j]);
			if (matrix[i][j] > maxvalue)
				return 0;
		}
	return matrix;

}

rgb **read_P3(FILE *in, int n, int m, int maxvalue)
{
	rgb **image;

	image = (rgb **)malloc(m * sizeof(rgb *));
	if (!image) {
		fprintf(stderr, "malloc() failled");
		return NULL;
	}
	for (int i = 0; i < m; i++) {
		image[i] = (rgb *)malloc(n * sizeof(rgb));
		if (!image[i]) {
			for (int j = 0; j < i; j++)
				free(image[j]);
		}
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n ; j++) {
			fscanf(in, "%d%d%d", &image[i][j].x, &image[i][j].y,
				   &image[i][j].z);
			if (image[i][j].x > maxvalue || image[i][j].y > maxvalue ||
				image[i][j].z > maxvalue)
				return 0;
		}

	return image;
}

int **read_P5(FILE *in, int n, int m, int maxvalue)
{
	int **matrix;
	matrix = (int **)malloc(m * sizeof(int *));
	if (!matrix) {
		fprintf(stderr, "malloc() failled");
		return NULL;
	}
	char car;
	fread(&car, sizeof(char), 1, in);
	for (int i = 0; i < m; i++) {
		matrix[i] = (int *)malloc(n * sizeof(int));
		if (!matrix[i]) {
			for (int j = 0; j < i; j++)
				free(matrix[j]);
		}
	}
	FILE *out = fopen("textoutput", "wt");

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			unsigned char aux;
			fread(&aux, sizeof(unsigned char), 1, in);
			matrix[i][j] = aux;
			if (aux > maxvalue)
				return 0;
		}

	fclose(out);
	return matrix;
}

rgb **read_P6(FILE *in, int n, int m, int maxvalue)
{
	rgb **image;
	image = (rgb **)malloc(m * sizeof(rgb *));
	if (!image) {
		fprintf(stderr, "malloc() failled");
		return NULL;
	}
	for (int i = 0; i < m; i++) {
		image[i] = (rgb *)malloc(n * sizeof(rgb));
		if (!image[i]) {
			for (int j = 0; j < i; j++)
				free(image[j]);
		}
	}

	unsigned char car;

	fread(&car, sizeof(unsigned char), 1, in);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			unsigned char aux;
			fread(&aux, sizeof(unsigned char), 1, in);
			image[i][j].x = aux;
			fread(&aux, sizeof(unsigned char), 1, in);
			image[i][j].y = aux;
			fread(&aux, sizeof(unsigned char), 1, in);
			image[i][j].z = aux;
			if (image[i][j].x > maxvalue || image[i][j].y > maxvalue ||
				image[i][j].z > maxvalue)
				return 0;
		}
	}
		return image;
}
