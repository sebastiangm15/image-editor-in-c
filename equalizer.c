//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "load.h"
#include "math.h"
#define NMAX 280

void equalize(int ***matrix, int type, int n, int m)
{
	if (type == 2) {
		printf("Black and white image needed\n");
	} else if (type == 0) {
		printf("No image loaded\n");
	} else {
		int vec_ap[NMAX] = {0};
		int area = n * m;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) // fac vectorul de aparitii
				vec_ap[(*matrix)[i][j]]++;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				int sum = 0;
/*dupa aceea calculez suma aparitiilor din vec_ap a numerelor mai mici decat
pixelul selectat fac rezultatul ca in formula din enut si dupa il rotunjesc*/
				for (int k = 0; k <= (*matrix)[i][j]; k++)
					sum = sum + vec_ap[k];
				double result = 0, calc = (double)1 / area;
				result = (double)255 * calc * sum;
				(*matrix)[i][j] = round(result);
			}
		printf("Equalize done\n");
	}
}
