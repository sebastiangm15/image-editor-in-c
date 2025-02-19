//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int select1(int *x1, int *x2, int *y1, int *y2, int n, int m, int type)
{
	char s[30];
	int ok = 0, nr = 0;

	if (type == 0) {
		printf("No image loaded\n");
		fgets(s, sizeof(s), stdin);
		return 0;
	}
	fgets(s, sizeof(s), stdin);
	int k = strchr(s, '\n') - s; // aflu pozitia '\n' si il inlocuiesc
	s[k] = '\0';
	int dim = strlen(s);
	for (int i = 0; i < dim; i++)
		if (s[i] == ' ')
			nr++; // aflu cate numere sunt in string
	if (nr != 4 && s[1] != 'A') {
		printf("Invalid command\n"); // daca sunt prea putine este invalid
		return 1;
	}
	char *p;
	p = strtok(s, " ");
/*verific in ce caz se incadreaza selectul*/
	if (strcmp(p, "ALL") == 0) {
		*x1 = 0, *y1 = 0, *x2 = n, *y2 = m;
		ok = 1;
		printf("Selected ALL\n");
		return 0;
	}
	if ((p[0] < '0' || p[0] > '9') && p[0] != '-') {
		printf("Invalid command\n");
		return 1;
	}
	*x1 = atoi(p); // extrag pe parcurs numerele din string
	p = strtok(NULL, " ");
	if ((p[0] < '0' || p[0] > '9') && p[0] != '-') {
		printf("Invalid command\n");
		return 1;
	}
	*y1 = atoi(p);
	p = strtok(NULL, " ");
	if ((p[0] < '0' || p[0] > '9') && p[0] != '-') {
		printf("Invalid command\n");
		return 1;
	}
	*x2 = atoi(p);
	p = strtok(NULL, " ");
	if ((p[0] < '0' || p[0] > '9') && p[0] != '-') {
		printf("Invalid command\n");
		return 1;
	}
	*y2 = atoi(p);
/*fac ordinea numerelor daca sunt puse invers*/
	if (*x2 < *x1) {
		int aux = *x2;
		*x2 = *x1;
		*x1 = aux;
	}
	if (*y2 < *y1) {
		int aux = *y2;
		*y2 = *y1;
		*y1 = aux;
	}
	if (*y1 == *y2) {
		printf("Invalid set of coordinates\n");
		return 1;
	}
	if (*x1 == *x2) {
		printf("Invalid set of coordinates\n");
		return 1;
	}
/*verific conditiile de validitate*/
	if (*x1 < 0 || *y1 < 0 || (*x1 == *x2 && *y1 == *y2) ||
		*x2 < 0 || *y2 < 0 || *x2 > n || *y2 > m) {
		printf("Invalid set of coordinates\n");
		return 1;
	}
		if (ok != 1)
			printf("Selected %d %d %d %d\n", *x1, *y1, *x2, *y2);
		return 0;
}
