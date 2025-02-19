//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define NMAX 280

void histogram(int **matrix, int type, int n, int m)
{
	int x, y, vec_af[NMAX] = {0}, maxi, nr = 0;
	char s[30], *p;

	fgets(s, 30, stdin); // citim tot sirul
	if (type == 0) { //cazul in care imaginea nu exista
		printf("No image loaded\n");
		return;
	}
	if (s[0] == '\n') {//inseamna ca in sirul citit nu sunt numere
		printf("Invalid command\n");
		return;
	}
	for (int i = 0; i < 30; i++)
		if (s[i] == '\n')
			s[i] = '\0';//punem terminatorul de sir
	for (int i = 0; i < (int)strlen(s); i++)
		if (s[i] == ' ')
			nr++; //aflam cate numere sunt in sir
	if (nr != 2) {
		printf("Invalid command\n");
		return;
	}
/*extragem numerele din string*/
	p = strtok(s, " ");
	x = atoi(p);
	p = strtok(NULL, " ");
	y = atoi(p);

	if (type == 2) { //verificam daca imaginea este color
		printf("Black and white image needed\n");
	} else {
		int v[NMAX] = {0};
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				v[matrix[i][j]]++; // facem vectorul de aparitii

		int number = 256 / y;
/*formam un vectorul de aparitii pe cate binuri trebuie*/
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < number; j++)
				vec_af[i] = v[i * number + j] + vec_af[i];
		}
		maxi = 0;
		for (int i = 0; i < y; i++)
			if (maxi < vec_af[i])
				maxi = vec_af[i]; // cautam maximul in vectorul format
		for (int i = 0; i < y; i++) {
			int stars = ((double)vec_af[i] / maxi) * x;
		printf("%d\t|\t", stars);
		for (int i = 0; i < stars; i++)
			printf("*");
		printf("\n");
		}

	}

}
