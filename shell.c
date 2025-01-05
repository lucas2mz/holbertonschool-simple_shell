#include "main.h"

int main(void)
{
	char *linea = NULL, *path = _getenv("PATH"), *full_path;
	size_t size = 0;
	ssize_t len = 0;
	char **args = malloc(sizeof(char *) * 1024);
	int status, i;
	pid_t hijo;

	print2();
	while (1)
	{
		printf("Shellzilla$ ");
		len = getline(&linea, &size, stdin);
		if (len == -1)
		{
			free(linea);
			break;
		}
		if (strcmp(linea, "exit\n") == 0)
		{
			free(linea);
			break;
		}
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
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			continue;
		}
		hijo = fork();
		if (hijo == 0)
		{
			if (execve(full_path, args, NULL) == -1)
			{
				perror("Execve");
				free(full_path);
				for (i = 0; args[i] != NULL; i++)
					free(args[i]);
				free(args);
				free(linea);
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
		free(full_path);
		free(args);
	}
	free(linea);
	return (0);
}
