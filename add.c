#include "main.h"

int add(task_t **head, int nb, const char *dateStart, const char *dateEnd, const char *description)
{
	task_t *new_node;

	new_node = (task_t *) malloc(sizeof(task_t));
	if (new_node == NULL)
		return (0);

	new_node->nb = nb;
	new_node->dateStart = strdup(dateStart);
	new_node->dateEnd = strdup(dateEnd);
	new_node->description = strdup(description);
	new_node->next = *head;
	*head = new_node;
	return (1);
}