#include "main.h"

int main(void)
{
	extern char **environ;
	char *linea = NULL, *path = _getenv("PATH"), *full_path = NULL;
	char **args;
	int status;
	pid_t hijo;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Shellzilla$ ");

		if (_getenv("TERM") == NULL)
    			setenv("TERM", "xterm", 1);

		if (leer_linea(&linea) == 0)
			break;

		args = tokenizar(linea, " \n\t");
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}
		full_path = check_command(args[0], path);
		if (full_path == NULL)
		{
			printf("Shellzilla: No such file or directory\n");
			limpiar(linea, args, full_path);
			continue;
		}
		hijo = fork();
		if (hijo == 0)
		{
			if (execve(full_path, args, environ) == -1)
			{
				perror("Execve");
				limpiar(linea, args, full_path);
				exit(1);
			}
		}
		else
			wait(&status);

		limpiar(linea, args, full_path);
	}
	free(linea);
	return (0);
}
