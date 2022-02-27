#include "queue.h"
#include <stdlib.h>
#include <string.h>

int enqueue(struct studentqueue *q, const char *name)
{

    struct studentqueue *new_node = malloc(sizeof(struct studentqueue));
    if (new_node == NULL) {
        return 0;
    }

    new_node->name = malloc(strlen(name) + 1);
    if (new_node->name == NULL) {
        free(new_node);
        return 0;
    }

    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (q->next == NULL) {
        q->next = new_node;
    } else {
        struct studentqueue *current = q->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
    if (q->next == NULL) {
        return 0;
    }

    struct studentqueue *old_node = q->next;
    q->next = old_node->next;

    strncpy(buffer, old_node->name, size);
    buffer[size - 1] = 0;

    free(old_node->name);
    free(old_node);

    return 1;
}