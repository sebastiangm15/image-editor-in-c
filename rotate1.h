//315CA-Gilma Sebastian Mihai
#pragma once
#include "load.h"

void rotate(int x1, int x2, int y1, int y2, int *n, int *m, int type,
			int ***matrix, rgb * **image);

void move_right_seg(int ****matrix, int x1, int x2, int y1, int y2);

void move_right(int ****matrix, int n, int m, int tipe_execution);

void move_right_rgb(rgb ****image,  int x1, int x2, int y1, int y2);

void move_right_all_rgb(rgb ****image, int n, int m, int tipe_execution);

void grades_func(int grades, int *number);
