#include "monty.h"

void init_monty(void);

/**
 * main - batch mode for monty byte code interpreter
 * @argc: number of command line arguments
 * @argv: arguments vector
 * Return: 0 on sucess, -1 on error
 */
int main(int argc, char *argv[])
{
	char *cmdLine = NULL; /* the shell command line */
	char **args = NULL; /*vector of arguments in a cmd: must free */
	size_t buffsz = 0; /* the cmdLine buffer size */
	ssize_t userInput = -1;  /* num of chars; -1 is error or EOF (CTRL+D)*/
	int fd;

	init_monty();
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* read and process each line until EOF */
	while (1)
	{
		lctl.jobNr++;
		userInput = _getline(&cmdLine, &buffsz, fd);
		if (userInput == -1)  /* error or EOF (CTRL+D) */
			break;
		remCmnt(cmdLine);  /* test */
		args = parseLine(cmdLine, " \n");  /*debug */
		if (execOpcode(args) == -1)   /* debug */
		{
			free(cmdLine);
			free(args);
			exit(EXIT_FAILURE);
		}
		free(cmdLine);/*  debug */
		free(args);  /*debug */
		cmdLine = NULL; /*debug */
		buffsz = 0;
	}
	free(cmdLine);
	return (0);
}

/**
 * init_monty - initialise the monty interpreter
 */
void init_monty(void)
{
	lctl.jobNr = 0;
	lctl.mode = 0;
	lctl.head = NULL;
	lctl.tail = NULL;
}
