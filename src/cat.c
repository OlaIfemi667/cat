#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
/**
 * main - C'est la fonction principale de ce projet
 * programmer l'utilitaire cat en C
 * Return: 0 quand la function s'exécute bien et autre exit code selon les cas
 */

int main(int argc, char *argv[])
{
	char *path = NULL;
	/*On laisse getcwd allouer a mémoire*/
	path = getcwd(NULL, 0);
	if (path != NULL)
	{
		printf("Vous vous trouvez dans le dossier suivant: %s\n", path);
	}
	else
	{
		perror("Nous ne trouvons pas le dossier courant");
		return (EXIT_FAILURE);
	}

	if (argc == 2)
	{
		char *completePath;
		int ch = '\0', lp = strlen(path), lr = strlen(argv[1]);
		completePath = (char *) malloc(sizeof(char) * (lr + lp) + 1);
		strcat(completePath, path);
		strcat(completePath, "/");
		strcat(completePath, argv[1]);
		printf("Vous voulez que j'affiche ce fichier \"%s\" \n\n", completePath);

		FILE *fptr;
		fptr = fopen(completePath, "r");
		
		if (fptr == NULL)
		{
			printf("Le ficher \"%s\" n'existe pas\n\n", argv[1]);
			exit(0);
		}
		while((ch = fgetc(fptr)) != EOF)
		{
			putchar(ch);
		}
		
		fclose(fptr);

		/*Liberer l'espace*/
		free(completePath);
	}

	/*Libérer l'espace mémore*/
	free(path);
	return (0);
}
