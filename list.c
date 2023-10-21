#include "main.h"

int list(const task_t *h)
{
	const task_t *current = h;
	int n = 0;

	while (current != NULL)
	{
		if (!current->description)
			printf("There is no task \n");
		else
		{
			printf("Task number [%d]\n", current->nb);
			printf("From [%s] \n", current->dateStart);
			printf("To [%s] \n", current->dateEnd);
			printf("Task : %s \n\n", current->description);
		}
		n++;
		current = current->next;
	}
	return(n);
}