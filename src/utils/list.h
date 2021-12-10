/*
** EPITECH PROJECT, 2021
** list
** File description:
** linked lists
*/

#include <stdlib.h>
#include <stdio.h>

#ifndef LIST_H_
#define LIST_H_

typedef struct list_data_s
{
    void *data;
    void *(destroy);
}list_data_t;

typedef struct list_s
{
    void *data;
    struct list_s *next;
}list_t;

void list_destroy(list_t **);

list_t *list_push_back(list_t **, void *data);

int list_size(list_t *);

#endif /* !LIST_H_ */
