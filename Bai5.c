#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    int priority;
    char data[50];
} Element;

typedef struct
{
    Element array[MAX];
    int size;
} PriorityQueue;

void initPriorityQueue(PriorityQueue *queue)
{
    queue->size = 0;
}

int isEmpty(PriorityQueue *queue)
{
    return queue->size == 0;
}

void enqueue(PriorityQueue *queue, int priority, char *data)
{
    if (queue->size == MAX)
    {
        printf("Hang doi da day. Khong the them phan tu.\n");
        return;
    }

    int i = queue->size - 1;
    while (i >= 0 && queue->array[i].priority > priority)
    {
        queue->array[i + 1] = queue->array[i];
        i--;
    }

    queue->array[i + 1].priority = priority;
    strcpy(queue->array[i + 1].data, data);
    queue->size++;

    printf("Da them phan tu (%d, \"%s\") vao hang doi.\n", priority, data);
}

Element dequeue(PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Hang doi rong. Khong the lay phan tu.\n");
        Element empty = {-1, ""};
        return empty;
    }

    Element highestPriorityElement = queue->array[0];

    for (int i = 0; i < queue->size - 1; i++)
    {
        queue->array[i] = queue->array[i + 1];
    }
    queue->size--;

    printf("Da lay phan tu (%d, \"%s\") ra khoi hang doi.\n", highestPriorityElement.priority, highestPriorityElement.data);
    return highestPriorityElement;
}

Element peek(PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Hang doi rong. Khong co phan tu de truy xuat.\n");
        Element empty = {-1, ""};
        return empty;
    }
    return queue->array[0];
}

// In trạng thái hàng đợi
void printQueue(PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Trang thai hang doi: \n");
    for (int i = 0; i < queue->size; i++)
    {
        printf("(%d, \"%s\") ", queue->array[i].priority, queue->array[i].data);
    }
    printf("\n");
}

int main()
{
    PriorityQueue queue;
    initPriorityQueue(&queue);

    enqueue(&queue, 2, "Task A");
    printQueue(&queue);

    enqueue(&queue, 1, "Task B");
    printQueue(&queue);

    enqueue(&queue, 3, "Task C");
    printQueue(&queue);

    Element element = dequeue(&queue);
    printQueue(&queue);

    element = dequeue(&queue);
    printQueue(&queue);

    return 0;
}
