#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "../include/functions.h"

void printTheFile(char *currentPath, char *filename)
{
	printf("--------------------------------------------\n");
	printf("--------------------------------------------\n");
	char *completePath;
	int ch = 0, lp = strlen(filename), lr = strlen(currentPath);

	completePath = (char *) malloc(sizeof(char) * (lr + lp) + 2);
	if (completePath == NULL)
	{
		perror("Error malloc");
		exit(1);
	}

	snprintf(completePath, lr + lp + 2, "%s/%s", currentPath, filename);

	printf("Vous voulez que j'affiche ce fichier \"%s\" \n\n", completePath);
	FILE *fptr;

	fptr = fopen(completePath, "r");
	if (fptr == NULL)
	{
		printf("Le ficher \"%s\" n'existe pas\n\n", filename);
		exit(0);
	}
	while ((ch = fgetc(fptr)) != EOF)
	{
		putchar(ch);
	}
	fclose(fptr);
	/*Liberer l'espace mémoire*/
	free(completePath);

}
