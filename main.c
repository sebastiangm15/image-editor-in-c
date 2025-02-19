//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "string.h"
#include "load.h"
#include "stdlib.h"
#include "select.h"
#include "save.h"
#include "rotate1.h"
#include "crop.h"
#include "apply.h"
#include "histogram.h"
#include "equalizer.h"

int main(void)
{
	int n = 0, m = 0, type = 0, maxvalue, **matrix = NULL, x1 = 0, y1 = 0,
	x2 = 0, y2 = 0, oldx1 = 0, oldx2 = 0, oldy1 = 0, oldy2 = 0;
	char activity[20], typevar[4];
	rgb **image = NULL;

	scanf("%s", activity);

	while (strcmp(activity, "EXIT") != 0) {
		if (strcmp(activity, "LOAD") == 0) {
			load(&image, &matrix, &n, &m, &maxvalue, &type, typevar, &x2, &y2);
		}
		if (strcmp(activity, "SAVE") == 0) {
			save(image, matrix, type, n, m, typevar, maxvalue);
		}
		if (strcmp(activity, "SELECT") == 0) {
			if (select1(&x1, &x2, &y1, &y2, n, m, type) == 1) {
				x1 = oldx1;
				x2 = oldx2;
				y1 = oldy1;
				y2 = oldy2;
			} else { //daca a fost invalidat selectul iau valoriie vechi
				oldx1 = x1;
				oldx2 = x2;
				oldy1 = y1;
				oldy2 = y2;
			}
		}
		if (strcmp(activity, "CROP") == 0) {
			crop(&x1, &x2, &y1, &y2, &n, &m, &image, &matrix, type);
		}
		if (strcmp(activity, "ROTATE") == 0) {
			rotate(x1, x2, y1, y2, &n, &m, type, &matrix, &image);
		}
		if (strcmp(activity, "EQUALIZE") == 0) {
			equalize(&matrix, type, n, m);
		}
		if (strcmp(activity, "APPLY") == 0) {
			char c[4];
			c[0] = '\0';
			if (type == 0) {
				printf("No image loaded\n");
			} else {
				fgets(c, 2, stdin);
				c[3] = '\0';
				if (strchr(c, '\n') != 0) {
					printf("Invalid command\n");
				} // verific daca nu am primit niciun parametru
			}
			if (strchr(c, '\n') == 0 && type != 0)
				apply(&image, n, m, type, x1, x2, y1, y2);
		}
		if (strcmp(activity, "HISTOGRAM") == 0) {
			histogram(matrix, type, n, m);
		}
		scanf("%s", activity);
	}

	if (type == 0) {
		printf("No image loaded\n");
	} else {//la final cu ajutorul variabilei type dau free matricei ramase
		if (type == 1) {
			for (int i = 0; i < m; i++)
				free(matrix[i]);
			free(matrix);
		} else {
			for (int i = 0; i < m; i++)
				free(image[i]);
			free(image);
		}
	}
	return 0;
}
