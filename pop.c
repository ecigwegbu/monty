#include "monty.h"

/**
 * _pop - delete a node at index 0 in a dbly lked list
 * Return: 1 if it succeeded, -1 if it failed
 */
int _pop(void)
/*void pop(stack_t **head, unsigned int index) */
{
	stack_t *tmp;

	if (lctl.head == NULL)	/* empty list case */
	{
		printf("L%d: can't pop an empty stack\n", lctl.jobNr);
		return (-1);
	}
	if (lctl.head->next)	/* not the only node */
	{
		tmp = lctl.head;
		lctl.head = lctl.head->next;
		free(tmp);
		lctl.head->prev = NULL;
	}
	else	/* single node case */
	{
		free(lctl.head);
		lctl.head = NULL;
		lctl.tail = NULL;
	}
	return (0);
}
