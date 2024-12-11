#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int array[MAX];
    int front;
    int rear;
} Queue;

// Khởi tạo hàng đợi
void initQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

// Kiểm tra hàng đợi đầy
int isFull(Queue *queue)
{
    return (queue->rear + 1) % MAX == queue->front;
}

// Thêm phần tử vào hàng đợi
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
}

// In ra các phần tử trong hàng đợi
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
    printf("Nhap gia tri phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    printQueue(&queue);

    return 0;
}
