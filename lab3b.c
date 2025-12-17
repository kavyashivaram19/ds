#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;
int isFull()
{
    if ((front == rear + 1) ||
        (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}
int isEmpty()
{
    if (front == -1) return 1;
    return 0;
}
int deQueue()
{
    int element;
    if (isEmpty())
    {
        printf("\n Queue is empty! \n");
        return (-1);
    }
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("\n Deleted element %d \n", element);
        return (element);
    }
}
void enQueue(int element)
{
    if (isFull())
        printf("\n Queue is full! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted %d", element);
    }
}

void display()
{
    int i;
    if (isEmpty())
        printf("\n Empty Queue\n");
    else
    {
        printf("\n Items ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
    }
}

int main()
{
    int option, val, del;
    do
    {
        printf("\n***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Display the queue");
        printf("\n 4. Exit");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the number to be inserted in the queue : ");
            scanf("%d", &val);
            enQueue(val);
            break;
        case 2:
            del = deQueue();
            printf("\n The number deleted is : %d", del);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    } while (option != 4);
    return 0;
}
