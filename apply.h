//315CA-Gilma Sebastian Mihai
#pragma once
#include "load.h"

void apply(rgb * **image, int n, int m, int type, int x1, int x2,
		   int y1, int y2);

void apply_blur(int ****matrix, int n, int m, int type, int x1, int x2, int y1,
				int y2);

void apply_gausian(int ****matrix, int n, int m, int type, int x1, int x2,
				   int y1, int y2);

void apply_sharpen(int ****matrix, int n, int m, int type, int x1, int x2,
				   int y1, int y2);

void apply_edge(int ****matrix, int n, int m, int type, int x1, int x2,
				int y1, int y2);

void apply_rgb(rgb ****image, int n, int m, int x1, int x2, int y1, int y2,
			   double a, double b, double c);
