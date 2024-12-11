#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int array[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

int isFull(Queue *queue)
{
    return (queue->rear + 1) % MAX == queue->front;
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Hang doi da day. Khong the them phan tu.\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->array[queue->rear] = value;
    printf("Da them %d vao hang doi.\n", value);
}

int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Hang doi rong. Khong co phan tu nao de truy xuat.\n");
        return -1;
    }
    return queue->array[queue->front];
}

void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Cac phan tu trong hang doi:\n");
    int i = queue->front;
    while (1)
    {
        printf("%d ", queue->array[i]);
        if (i == queue->rear)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Queue queue;
    initQueue(&queue);
    int n, value;

    printf("Nhap so luong phan tu can them vao hang doi: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&queue, value);

        int frontValue = peek(&queue);
        if (frontValue != -1)
        {
            printf("Phan tu dau tien trong hang doi: %d\n", frontValue);
        }
    }

    printQueue(&queue);

    return 0;
}
