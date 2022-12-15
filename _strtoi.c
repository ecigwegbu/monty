#include "monty.h"

int _checkError(int *sign, const char **ptr);
/**
 * _strtoi - convert string to 32-bit integer
 * @str: the string to convert to integer
 * @error: error indicator - 0, unless an error occurs then -1
 *
 * Return: the resulting integer, or 9 9's when an error occurs, e is set to -1
 */
int _strtoi(const char *str, int *error)
{
	int sign = 1;
	long n = 0;
	const char *ptr = str;

	*error = -1; /* default outcome is error */
	if (_checkError(&sign, &ptr))
		return (999999999);

	n = 0;
	while (*ptr)
	{
		if (*ptr < '0' || *ptr > '9')
			return (999999999);
		n = (n * 10) + (*ptr - '0');
		ptr++;
	}

	if (n > 2147483647)
		return (999999999);

	if (sign == -1)
		n = -n;

	*error = 0; /* no error occured */
	return ((int) n);
}
/**
 * _checkError - check for errors in input
 * @sign: integer sign - + or -
 * @ptr: pointer used for iteration
 * Return: -1 on error or 0 otherwise
 */
int _checkError(int *sign, const char **ptr)
{
	if (*ptr == NULL)
		return (-1);

	if (**ptr == '-')  /* negative integer */
	{
		*sign = -1;
		(*ptr)++;  /* skip the sign for now */
	}
	else if (**ptr == '+')
	{
		*sign = 1;
		(*ptr)++;
	}

	if (_strlen(*ptr) > 10) /* out of range */
		return (-1);

	return (0);
}
