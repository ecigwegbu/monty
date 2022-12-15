#include "monty.h"

int getSize(int n);

/**
 * _itostr - convert a 32-bit interger to a string
 * @n: the number
 * Return: pointer to the resulting string; 12 bytes, free later
 */

char *_itostr(int n)
{
	int sz = 0;
	char *str, *ptr;

	sz = getSize(n);
	str = malloc(sz);
	if (str == NULL)
	{
		perror("_itostr");
		exit(EXIT_FAILURE);  /*  out of memor */
	}

	ptr = str + (sz - 1);	/* points to where the terminating '\0' should be */
	*ptr = '\0'; /* set's it to '\0' */

	if (n >= 0)
	{
		do {
			*--ptr = '0' + (n % 10);
			n /= 10;
		} while (n != 0);
		return (ptr);
	}
	else
	{	/* i < 0 */
		do {
			*--ptr = '0' - (n % 10);
			n /= 10;
		} while (n != 0);
		*--ptr = '-';
	}

	if (ptr != str)
	{
		perror("_itostr: pointer mismatch");
		exit(EXIT_FAILURE);
	}
	return (str);
}

/**
 * getSize - determine the precise buffer size needed fpr the integer,
 * including the - sign
 * @n: the integer
 * Return: the buffer size, including the minus sign (but no plus sign)
 */
int getSize(int n)
{
	int sign = 1, sz = 0;

	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	if (n < 10)
		sz = 1;
	else if (n < 100)
		sz = 2;
	else if (n < 1000)
		sz = 3;
	else if (n < 10000)
		sz = 4;
	else if (n < 100000)
		sz = 5;
	else if (n < 1000000)
		sz = 6;
	else if (n < 10000000)
		sz = 7;
	else if (n < 100000000)
		sz = 8;
	else if (n < 1000000000)
		sz = 9;
	else
		sz = 10;

	sz += 1;  /* for null byte */
	if (sign == -1)
		sz += 1;  /* for - sign */

	return (sz);
}

