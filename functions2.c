#include "main.h"
/**
 * ejecutar_comando - Executes command
 * @full_path: The command to execute
 * @args: Array null terminated
 *
 * Return: Always 0
 */
int ejecutar_comando(char *full_path, char **args)
{
	pid_t hijo;
	int status;

	hijo = fork();

	if (hijo == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("Execve");
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
/**
 * _env - Prints the enviroment
 */
void imprimir_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
/**
 * main_function - Does all the calls for the program
 */
void main_function(void)
{
	char *linea = NULL, *path = _getenv("PATH"), *full_path = NULL;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Shellzilla$ ");

		if (leer_linea(&linea) == 0)
			break;

		args = tokenizar(linea, " \n\t");
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}
		if (strcmp(args[0], "env") == 0)
		{
			imprimir_env();
			limpiar(linea, args, NULL);
			continue;
		}
		full_path = check_command(args[0], path);
		if (full_path == NULL)
		{
			fprintf(stderr, "Shellzilla: No such file or directory\n");
			limpiar(linea, args, full_path);
			continue;
		}

		ejecutar_comando(full_path, args);
		limpiar(linea, args, full_path);
	}
	free(linea);
}
