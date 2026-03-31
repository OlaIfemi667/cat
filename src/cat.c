#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "../include/functions.h"
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

	if (argc != 1)
	{
		for (int i = 1; i < argc; i++)
		{
			printTheFile(path, argv[i]);
		}
	}

	/*Libérer l'espace mémore*/
	free(path);
	return (0);
}
