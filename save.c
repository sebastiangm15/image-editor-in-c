//315CA-Gilma Sebastian Mihai
#include "stdio.h"
#include "load.h"
#include "string.h"

void save(rgb **image, int **matrix, int type, int length, int width,
		  char *typevar, int maxvalue)
{
	char s[50];

	if (type == 0) {
		printf("No image loaded\n");
		fgets(s, sizeof(s), stdin);
	} else {
		fgets(s, sizeof(s), stdin);
		memmove(s, s + 1, strlen(s));
		s[strlen(s) - 1] = '\0';
		if (strchr(s, ' ')) { //in caz ca apare ascii eu prelucrez doar numele
			int poz = strchr(s, ' ') - s;
			char newstring[50];
			for (int i = 0; i < poz; i++)
				newstring[i] = s[i];
			newstring[poz] = '\0';
 //obtin numele fisierul in care trebuie sa salvez
			FILE *out = fopen(newstring, "wt");
 //salvam in fisier
			printf("Saved %s\n", newstring);
			if (strcmp(typevar, "P5") == 0)
				fprintf(out, "P2\n");
			if (strcmp(typevar, "P6") == 0)
				fprintf(out, "P3\n");
			if (strcmp(typevar, "P3") == 0 || strcmp(typevar, "P2") == 0)
				fprintf(out, "%s\n", typevar);
			fprintf(out, "%d %d\n", length, width);
			fprintf(out, "%d\n", maxvalue);
			if (type == 1) {
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < length; j++)
						fprintf(out, "%d ", matrix[i][j]);
				fprintf(out, "\n");
				}
			} else {
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < length; j++)
						fprintf(out, "%d %d %d ",
								image[i][j].x, image[i][j].y, image[i][j].z);
				fprintf(out, "\n");
				}
			}
			fclose(out);
		} else {
			FILE *out = fopen(s, "wb");
			printf("Saved %s\n", s);
			if (strcmp(typevar, "P2") == 0)
				fprintf(out, "P5\n");
			if (strcmp(typevar, "P3") == 0)
				fprintf(out, "P6\n");
			if (strcmp(typevar, "P5") == 0 || strcmp(typevar, "P6") == 0)
				fprintf(out, "%s\n", typevar);

			fprintf(out, "%d %d\n", length, width);
			fprintf(out, "%d\n", maxvalue);

			if (type == 1) { // salvam octet cu octet in fisier
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < length; j++) {
						unsigned char aux = matrix[i][j];
						fwrite(&aux, sizeof(unsigned char), 1, out);
					}
				}
			} else { // salvam octet cu octet in fisier
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < length; j++) {
						unsigned char aux = image[i][j].x;
						fwrite(&aux, sizeof(unsigned char), 1, out);
						aux = image[i][j].y;
						fwrite(&aux, sizeof(unsigned char), 1, out);
						aux = image[i][j].z;
						fwrite(&aux, sizeof(unsigned char), 1, out);
					}
				}
			}
			fclose(out);
		}
	}
}
