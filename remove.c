#include "main.h"

void remove_task(task_t **head, int position) {
	 task_t *current = *head;
	 task_t *previous = NULL;

	 if (position < 1)
	 	printf("Task number incorrect \n\n");
     // Traverse the list to find the node with the value
    while (current != NULL && current->nb != position) {
        previous = current;
        current = current->next;
    }

    // If the node was found
    if (current != NULL) {
        // Update the links to bypass the current node
        if (previous == NULL) {
            // The node to remove is the head
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        // Free the memory of the removed node
		free(&(current->nb));
		free(current->dateStart);
		free(current->dateEnd);
		free(current->description);
        free(current);
		printf("Task removed successfully.\n\n");
    }
	else
		printf("Task doesn't exist \n\n");

    
}
