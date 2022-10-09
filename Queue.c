#include<stdio.h>
#define Max 5

void display();
void push();
void pop();
void commands() {
    printf("Operations : \n\t0 -> to print commands\n\t1 -> to push value in Queue\n\t2 - to pop value from Queue\n\t3 -> to display full Queue\n\t4 -> to exit from program\n");
}

int rear = -1, front = -1, i, choice, val;
int arr[Max];

void main() {
    commands();
    while(1) {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if (choice == 4) {
            printf("exiting...\nexited successfully\n");
            break;
        }
        switch (choice) {
            case 0 :
                commands();
                break;
            case 1 :
                push();
                break;
            case 2 :
                pop();
                break;
            case 3 :
                display();
                break;
            default :
                printf("Error 0 : \n\tThere is not such choice available :<\n");
                break;
        }
    }
}

void push() {
    if (rear >= Max-1) {
        printf("Error -1 : \n\tQueue Overflow Exception\n\tQueue is already full!!\n");
        return;
    }
    if (rear == -1 && front == -1) {
        front =  0;
    }
    rear++; 
    printf("Enter value to push into Queue : ");
    scanf("%d", &val);
    arr[rear] = val;
}

void pop() {
    if (front <= -1) {
        printf("Error 1 : \n\tQueue Underflow Exception\n\tPlease push some value in Queue to pop\n");
        return;
    }
    val = arr[front];
    printf("Value popped from Queue : %d\n", val);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    if (front > Max-1) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Error 0 : \n\tQueue is empty!!\n");
        return;
    }
    if (front > rear) {
        printf("Error 0 : \n\tQueue is empty!!\n");
        return;
    }
    printf("Queue : \n");
    for (int i = rear; i >= front; i--) {
        if (arr[i] <= 9 && arr[i] > -1) {
            printf("\t|0%d|\n", arr[i]);
        } else {
            printf("\t|%d|\n", arr[i]);
        }
    }
}