#include "monty.h"

/**
 * execOpcode - execute an opcode
 * @args: the arguments vector for the current command
 * Return: 0 if ok, -1 on error
 */
int execOpcode(char **args)
{

	if (!_strcmp(args[0], "push"))  /* arg matches this function */
	{

		if ((args[1] == NULL) ||
			((atoi(args[1]) == 0) && ((args[1][0]) != '0')))
		{
			printf("L%d: usage: push integer", lctl.jobNr);
			return (-1);
		}
		return (_push(atoi(args[1])));
	}
	else if (!_strcmp(args[0], "pall"))  /* arg matches this function */
		return (_pall());
	else if (!_strcmp(args[0], "pint"))  /* arg matches this function */
		return (_pint());
	else if (!_strcmp(args[0], "pop"))  /* arg matches this function */
		return (_pop());
	else if (!_strcmp(args[0], "swap"))  /* arg matches this function */
		return (_swap());
	else if (!_strcmp(args[0], "add"))  /* arg matches this function */
		return (_add());
	else if (!_strcmp(args[0], "nop"))  /* arg matches this function */
		return (0);
	else if (!_strcmp(args[0], "sub"))  /* arg matches this function */
		return (_sub());
	else if (!_strcmp(args[0], "div"))  /* arg matches this function */
		return (_div());
	else if (!_strcmp(args[0], "mul"))  /* arg matches this function */
		return (_mul());
	else if (!_strcmp(args[0], "mod"))  /* arg matches this function */
		return (_mod());
	else if (!_strcmp(args[0], "pchar"))  /* arg matches this function */
		return (_pchar());
	else if (!_strcmp(args[0], "pstr"))  /* arg matches this function */
		return (_pstr());

	printf("L%d: unknown instruction %s\n", lctl.jobNr, args[0]);
	return (-1);
}

