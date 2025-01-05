#include "main.h"
/*/
char *_strdup(char *string)
{
	char *aux = NULL;
	int i, j = 0, len = 0;
	
	if (string == NULL)
		return (NULL);
	while (string[j] != '\0')
	{
		len++;
		j++;
	}
	
	aux = malloc(sizeof(char *) * (len + 1));

	if (aux == NULL)
	{
		return (NULL);
	}

	for (i = 0; string[i] != '\0'; i++)
	{
		aux[i] = string[i];
	}
	aux[i] = '\0';
	return (aux);
}
int _strcmp(char *string1, char *string2)
{
	int i = 0;
	if (string1 == NULL || string2 == NULL)
	{
		return (-1);
	}
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] != string2[i])
		{
			return (-1);
		}
		i++;
	}
	if (string1[i] == '\0' && string2[i] == '\0')
	{
		return (0);
	}
	return (-1);
} */
char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *token;

	while (environ[i])
	{
		token = strtok(environ[i], "=");

		if (strcmp(token, name) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
	}
	return NULL;
}

char *check_command(char *command, char *path)
{
	char *full_path = malloc(sizeof(char *) * 1024);
	char *copy_path = strdup(path);
	struct stat st;
	char *token;

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			return (strdup(command));
		}
		return (NULL);
	}

	token = strtok(copy_path, ":");

	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, command);

		if (stat(full_path, &st) == 0)
		{
			free(copy_path);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}
	free(copy_path);
	free(full_path);
	return (NULL);
}

char **tokenizar(char *linea, char *delim)
{
	char **args = malloc(sizeof(char *) * 1024);
	char *token;
	int i = 0;

	token = strtok(linea, delim);

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;

	return (args);
}
