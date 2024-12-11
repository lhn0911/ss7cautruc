#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int array[MAX];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *deque)
{
    deque->front = -1;
    deque->rear = 0;
    deque->size = 0;
}

int isEmpty(Deque *deque)
{
    return deque->size == 0;
}

int isFull(Deque *deque)
{
    return deque->size == MAX;
}

void addFront(Deque *deque, int data)
{
    if (isFull(deque))
    {
        printf("Hang doi da day. Khong the them vao dau.");
        return;
    }

    if (deque->front == -1)
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->front == 0)
    {
        deque->front = MAX - 1;
    }
    else
    {
        deque->front--;
    }

    deque->array[deque->front] = data;
    deque->size++;
    printf("Da them %d vao dau hang doi.\n", data);
}

void addRear(Deque *deque, int data)
{
    if (isFull(deque))
    {
        printf("Hang doi da day. Khong the them vao cuoi.");
        return;
    }

    if (deque->front == -1)
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->rear == MAX - 1)
    {
        deque->rear = 0;
    }
    else
    {
        deque->rear++;
    }

    deque->array[deque->rear] = data;
    deque->size++;
    printf("Da them %d vao cuoi hang doi.\n", data);
}

int removeFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Hang doi rong. Khong the lay phan tu o dau.\n");
        return -1;
    }

    int data = deque->array[deque->front];
    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->front == MAX - 1)
    {
        deque->front = 0;
    }
    else
    {
        deque->front++;
    }

    deque->size--;
    printf("Da lay %d tu dau hang doi.\n", data);
    return data;
}

int removeRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Hang doi rong. Khong the lay phan tu o cuoi.\n");
        return -1;
    }

    int data = deque->array[deque->rear];
    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->rear == 0)
    {
        deque->rear = MAX - 1;
    }
    else
    {
        deque->rear--;
    }

    deque->size--;
    printf("Da lay %d tu cuoi hang doi.\n", data);
    return data;
}

void printDeque(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Trang thai hang doi: ");
    int i = deque->front;
    while (1)
    {
        printf("%d ", deque->array[i]);
        if (i == deque->rear)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Deque deque;
    initDeque(&deque);

    addFront(&deque, 10);
    printDeque(&deque);

    addRear(&deque, 20);
    printDeque(&deque);

    addFront(&deque, 5);
    printDeque(&deque);

    removeFront(&deque);
    printDeque(&deque);

    removeRear(&deque);
    printDeque(&deque);

    return 0;
}
