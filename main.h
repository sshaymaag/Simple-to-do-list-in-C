#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct task
{
	int nb;
    char *dateStart;
	char *dateEnd;
	char *description;
	struct task* next;
}task_t;

void menu(void);
int list(const task_t *h);
int add(task_t **head, int nb, const char *dateStart, const char *dateEnd, const char *description);
void remove_task(task_t **head, int position);

#endif