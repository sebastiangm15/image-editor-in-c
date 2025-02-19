//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "load.h"
#include "stdlib.h"

void crop(int *x1, int *x2, int *y1, int *y2, int *n, int *m,
		  rgb ***image, int ***matrix, int type)
{
	if (type == 0) {
		printf("No image loaded\n");
	} else {
		if (type == 2) {
			rgb **copy; // aloc o noua matrice
			copy = (rgb **)malloc((*y2 - *y1) * sizeof(rgb *));
			if (!copy) {
				fprintf(stderr, "malloc() failled");
			}
			for (int i = 0; i < *y2 - *y1; i++) {
				copy[i] = (rgb *)malloc((*x2 - *x1) * sizeof(rgb));
				if (!copy[i]) {
					for (int j = 0; j < i; j++)
						free(copy[j]);
				}
			} //copiez valorile din matricea existenta de pe pozitiile cerute
			for (int i = *y1; i < *y2; i++)
				for (int j = *x1; j < *x2; j++) {
					copy[i - *y1][j - *x1] = (*image)[i][j];
				}
			for (int i = 0; i < *m; i++)
				free((*image)[i]);
			free(*image);
			*image = copy;

		} else {
			int **copy;// aloc o noua matrice
			copy = (int **)malloc((*y2 - *y1) * sizeof(int *));
			if (!copy) {
				fprintf(stderr, "malloc() failled");

			}
			for (int i = 0; i < *y2 - *y1; i++) {
				copy[i] = (int *)malloc((*x2 - *x1) * sizeof(int));
				if (!copy[i]) {
					for (int j = 0; j < i; j++)
						free(copy[j]);
				}
			} //copiez valorile din matricea existenta de pe pozitiile cerute
			for (int i = *y1; i < *y2; i++)
				for (int j = *x1; j < *x2; j++) {
					copy[i - *y1][j - *x1] = (*matrix)[i][j];
				}
			for (int i = 0; i < *m; i++)
				free((*matrix)[i]);
			free(*matrix);
			*matrix = copy;

		}
		*n = *x2 - *x1;//la final schimb indicii cu cei noi dupa crop
		*m = *y2 - *y1;
		*y2 = *m;
		*x2 = *n;
		*y1 = 0;
		*x1 = 0;
		printf("Image cropped\n");
	}

}
