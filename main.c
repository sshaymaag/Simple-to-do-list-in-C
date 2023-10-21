#include "main.h"

int main(void)
{
	int x, nb = 0;
	task_t *head;
	head = NULL;
	menu();
    scanf("%d", &x);  
	while (x != 4)
	{
			
		if (x == 1)
		{
			int n;
			printf("\n --- Tasks ---\n");
			n = list(head);
			if (n == 0)
				printf("There is no tasks \n\n");
		}
		else if (x == 2)
		{
			int r;
			char *dateStart = (char *)malloc(10);
			char *dateEnd = (char *)malloc(10);
			char *description = (char *)malloc(200);

			printf("Start date : ");
			scanf("%s", dateStart);
			getchar();
			printf("End date : ");
			scanf("%s", dateEnd);
			getchar(); // Consume the newline character left by scanf
			printf("Description : ");
			fgets(description, 200, stdin); 
			description[strcspn(description, "\n")] = '\0'; // Remove the newline character

			nb++;
			r = add(&head, nb, dateStart, dateEnd, description);

			if (r == 1)
			{
				printf("\nInserted succefully\n\n");
				free(dateStart);
				free(dateEnd);
				free(description);
			}
			else
			{
				printf("\nSomething went wrong !\n\n");
				nb--;
			}
		}
		else if (x == 3)
		{
			int remove = 0, n;
			printf("\n --- Tasks ---\n\n");
			n = list(head);
			
			if (n == 0)
				printf("There is no tasks \n");
			else
			{
				printf("Put the number of the task you want to remove : ");
				scanf("%d", &remove);
				remove_task(&head, remove);
			}
		}
		else
		{
			printf("Command not correct !\n");
		}
		menu();
    	scanf("%d", &x);  
	}
	task_t *temp = head;

	while (temp != NULL)
	{
		head = head->next;
		free(temp->dateStart);
		free(temp->dateEnd);
		free(temp->description);
		free(temp);
		temp = head;
	}
	
	return(0);
}