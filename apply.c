//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "apply.h"
#include "load.h"

void apply(rgb ***image, int n, int m, int type, int x1, int x2, int y1, int y2)
{
	char s[30];
	if (type == 0) {
		printf("No image loaded\n");
	} else if (type == 1) {
		printf("Easy, Charlie Chaplin\n");
	} else if (type == 2) {
		scanf("%s", s);
		int ok = 0; //verific ce filtru trebuie aplicat pe imagine
		if (strstr(s, "BLUR") != 0 && strstr(s, "GAUSSIAN") == 0) {
			double a, b, c;
			ok = 1; //numerele a b si c reprezinta:
			a = (double)1 / 9; //centrul
			b = (double)1 / 9; //pozitiile din + excluzand centrul
			c = (double)1 / 9; //pozitiile din x excluzand centrul
			apply_rgb(&image, n, m, x1, x2, y1, y2, a, b, c);
		}
		if (strstr(s, "GAUSSIAN") != 0) {
			double a, b, c;
			ok = 1;
			a = (double)4 / 16;
			b = (double)2 / 16;
			c = (double)1 / 16;
			apply_rgb(&image, n, m, x1, x2, y1, y2, a, b, c);
		}
		if (strstr(s, "SHARPEN") != 0) {
			double a, b, c;
			ok = 1;
			a = (double)5;
			b = (double)-1;
			c = (double)0;
			apply_rgb(&image, n, m, x1, x2, y1, y2, a, b, c);
		}
		if (strstr(s, "EDGE") != 0) {
			double a, b, c;
			ok = 1;
			a = (double)8;
			b = (double)-1;
			c = (double)-1;
			apply_rgb(&image, n, m, x1, x2, y1, y2, a, b, c);
		}
		if (ok == 1) {
			printf("APPLY %s done\n", s);
		} else {
			printf("APPLY parameter invalid\n");
		}
	}
}

void apply_rgb(rgb ****image, int n, int m, int x1,
			   int x2, int y1, int y2, double a, double b, double c)
{
	rgb **copy = (rgb **)malloc((y2 - y1) * sizeof(rgb *));
	for (int i = 0; i < y2 - y1; i++)
		copy[i] = (rgb *)malloc((x2 - x1) * sizeof(rgb));
	for (int i = y1; i < y2; i++)
		for (int j = x1; j < x2; j++) {
			if (i == 0 && j == 0) { //verific ca pixelul sa nu fie pe contur
				copy[i - y1][j - x1] = (**image)[i][j];
			} else if (i == m - 1 && j == 0) {
				copy[i - y1][j - x1] = (**image)[i][j];
			} else if (j == n - 1 && i == 0) {
				copy[i - y1][j - x1] = (**image)[i][j];
			} else if (i == 0) {
				copy[i - y1][j - x1] = (**image)[i][j];
			} else if (j == 0) {
				copy[i - y1][j - x1] = (**image)[i][j];
			} else if (i == m - 1 && j == n - 1) {
				copy[i - y1][j - x1] = (**image)[i][j];
			} else if (i == m - 1) {
				copy[i - y1][j - x1] = (**image)[i][j];
			} else if (j == n - 1) {
				copy[i - y1][j - x1] = (**image)[i][j];
			} else { //efectuez calculul matematic corespunzator fiecarui filtru
				double result = 0;
				result = b * (**image)[i + 1][j].x + a * (**image)[i][j].x
				+ b * (**image)[i][j + 1].x + c * (**image)[i + 1][j + 1].x
				+ c * (**image)[i - 1][j - 1].x + b * (**image)[i][j - 1].x
				+ b * (**image)[i - 1][j].x + c * (**image)[i - 1][j + 1].x
				+ c * (**image)[i + 1][j - 1].x;

				copy[i - y1][j - x1].x = round(result);
				result = b * (**image)[i + 1][j].y + a * (**image)[i][j].y
				+ b * (**image)[i][j + 1].y + c * (**image)[i + 1][j + 1].y
				+ c * (**image)[i - 1][j - 1].y + b * (**image)[i][j - 1].y
				+ b * (**image)[i - 1][j].y + c * (**image)[i - 1][j + 1].y
				+ c * (**image)[i + 1][j - 1].y;

				copy[i - y1][j - x1].y = round(result);
				result = b * (**image)[i + 1][j].z + a * (**image)[i][j].z +
				b * (**image)[i][j + 1].z + c * (**image)[i + 1][j + 1].z
				+ c * (**image)[i - 1][j - 1].z + b * (**image)[i][j - 1].z
				+ b * (**image)[i - 1][j].z + c * (**image)[i - 1][j + 1].z
				+ c * (**image)[i + 1][j - 1].z;
				copy[i - y1][j - x1].z = round(result);
			}
		}
	for (int i = y1; i < y2; i++)
		for (int j = x1; j < x2; j++) { //verific ca valoarea sa fie in [0,255]
			(**image)[i][j] = copy[i - y1][j - x1];
			if ((**image)[i][j].x < 0)
				(**image)[i][j].x = 0;
			if ((**image)[i][j].y < 0)
				(**image)[i][j].y = 0;
			if ((**image)[i][j].z < 0)
				(**image)[i][j].z = 0;
			if ((**image)[i][j].x > 255)
				(**image)[i][j].x = 255;
			if ((**image)[i][j].y > 255)
				(**image)[i][j].y = 255;
			if ((**image)[i][j].z > 255)
				(**image)[i][j].z = 255;
		}
	for (int i = 0; i < y2 - y1; i++)
		free(copy[i]);
	free(copy);
}
