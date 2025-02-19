//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "stdlib.h"
#include "load.h"
#include "rotate1.h"

void rotate(int x1, int x2, int y1, int y2, int *n, int *m,
			int type, int ***matrix, rgb ***image)
{
	int tipe_execution = 2, grades;

	scanf("%d", &grades);
	if (type == 0) {
		printf("No image loaded\n");
		tipe_execution = 0;
	} else if (grades % 90 != 0) {
		printf("Unsupported rotation angle\n");
		tipe_execution = 0;
	} else if (type == 1) {

		if (*n == x2 && *m == y2 && y1 == 0 && x1 == 0)
			tipe_execution = 1;
		if (grades > 0) {
			int i = 0;
			while (i < grades / 90) {
				if (tipe_execution == 1) {
					move_right(&matrix, x2, y2, tipe_execution);
					int aux = *n;
					*n = *m, *m = aux, aux = x2, x2 = y2, y2 = aux;
//daca trebuie sa invart toata imaginea schimb si indicii
				} else {
					move_right_seg(&matrix, x1, x2, y1, y2);
				}
				i++;
			}
		} else {
			int number = 0, i = 0; //pentru cazule negativ
			grades_func(grades, &number); //aflam de cate ori trebuie sa rotim
			while (i < number) {
				if (tipe_execution == 1) {
					move_right(&matrix, x2, y2, tipe_execution);
					int aux = *n;
					*n = *m, *m = aux, aux = x2, x2 = y2, y2 = aux;
				} else {
					move_right_seg(&matrix, x1, x2, y1, y2);
				}
				i++;
			}
		}
	} else {
		if (*n == x2 && *m == y2 && x1 == 0 && y1 == 0)
			tipe_execution = 1;
		if (grades > 0) {
			int i = 0;
			while (i < grades / 90) {
				if (tipe_execution == 1) {
					move_right_all_rgb(&image, x2, y2, tipe_execution);
					int aux = *n;
					*n = *m, *m = aux, aux = x2, x2 = y2, y2 = aux;
				} else {
					move_right_rgb(&image, x1, x2, y1, y2);
				}
				i++;
			}
		} else {
			int number = 0;
			grades_func(grades, &number);
			int i = 0;
			while (i < number) {
				if (tipe_execution == 1) {
					move_right_all_rgb(&image, x2, y2, tipe_execution);
					int aux = *n;
					*n = *m, *m = aux, aux = x2, x2 = y2, y2 = aux;
				} else {
					move_right_rgb(&image, x1, x2, y1, y2);
				}
				i++;
			}
		}
	}
	if (tipe_execution != 0)
		printf("Rotated %d\n", grades);
}

void grades_func(int grades, int *number)
{
	if (grades == -90)
		*number = 3;
	if (grades == -180)
		*number = 2;
	if (grades == -270)
		*number = 1;
	if (grades == -360)
		*number = 0;
}

void move_right(int ****matrix, int n, int m, int tipe_execution)
{
		int **aux; // cream o matrice copie in care facem rotatia
		aux = (int **)malloc((n) * sizeof(int *));
		if (!aux) {
			fprintf(stderr, "malloc() failled");
			return;
		}
		for (int i = 0; i < (n); i++) {
			aux[i] = (int *)malloc((m) * sizeof(int));
			if (!aux[i]) {
				for (int j = 0; j < i; j++)
					free(aux[j]);
			}
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) { //calculez transpusa matricei
			aux[j][i] = (**matrix)[i][j];
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < ((m) / 2); j++) {
			int auxvar = (aux)[i][j]; // apoi schimb coloanele astfel incat
			aux[i][j] = (aux)[i][(m - 1) - j]; //prima coloana sa fie ultima
			(aux)[i][(m - 1) - j] = auxvar; // si asa mai departe
		}

	if (tipe_execution == 1) {
		for (int i = 0; i < m; i++)
			free((**matrix)[i]);
		free(**matrix);
		**matrix = aux; // dupa rotatie matricea copie devine principala
	} else {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				(**matrix)[i][j] = (aux)[i][j];
		for (int i = 0; i < n; i++)
			free(aux[i]);
		free(aux);
	}
}

void move_right_seg(int ****matrix, int x1, int x2, int y1,
					int y2)
{
	int n = x2 - x1, m = y2 - y1;
	int **aux = (int **)malloc((n) * sizeof(int *));
	if (!aux) {
		fprintf(stderr, "malloc() failled");
		return;
	}
	for (int i = 0; i < (n); i++) {
		aux[i] = (int *)malloc((m) * sizeof(int));
		if (!aux[i]) {
			for (int j = 0; j < i; j++)
				free(aux[j]);
		}
	}
	for (int i = 0; i < n; i++) //cand matricea nu este dreptunghi
		for (int j = 0; j < m; j++) // o inversam cu ajutorul indicilor
			aux[j][n - i - 1] = (**matrix)[y1 + i][x1 + j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(**matrix)[y1 + i][x1 + j] = aux[i][j];
	for (int i = 0; i < n; i++)
		free(aux[i]);
	free(aux);

}

void move_right_rgb(rgb ****image,  int x1, int x2, int y1,
					int y2)
{
	int n = x2 - x1, m = y2 - y1;
	rgb **aux = (rgb **)malloc((n) * sizeof(rgb *));
	if (!aux) {
		fprintf(stderr, "malloc() failled");
		return;
	}
	for (int i = 0; i < (n); i++) {
		aux[i] = (rgb *)malloc((m) * sizeof(rgb));
		if (!aux[i]) {
			for (int j = 0; j < i; j++)
				free(aux[j]);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			aux[j][n - i - 1] = (**image)[y1 + i][x1 + j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(**image)[y1 + i][x1 + j] = aux[i][j];
	for (int i = 0; i < n; i++)
		free(aux[i]);
	free(aux);
}

void move_right_all_rgb(rgb ****image, int n, int m, int tipe_execution)
{
		rgb **aux;
		aux = (rgb **)malloc((n) * sizeof(rgb *));
		if (!aux) {
			fprintf(stderr, "malloc() failled");
			return;
		}
		for (int i = 0; i < (n); i++) {
			aux[i] = (rgb *)malloc((m) * sizeof(rgb));
			if (!aux[i]) {
				for (int j = 0; j < i; j++)
					free(aux[j]);
			}
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			aux[j][i] = (**image)[i][j];
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < ((m) / 2); j++) {
			rgb auxvar = (aux)[i][j];
			aux[i][j] = (aux)[i][(m - 1) - j];
			(aux)[i][(m - 1) - j] = auxvar;
		}

	if (tipe_execution == 1) {
		for (int i = 0; i < m; i++)
			free((**image)[i]);
		free(**image);
		**image = aux;
	} else {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				(**image)[i][j] = (aux)[i][j];
		for (int i = 0; i < n; i++)
			free(aux[i]);
		free(aux);
	}
}
