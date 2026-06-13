#include <stdio.h>
#include <stdlib.h>

#define Capacity 5
#define TRUE 1
#define FALSE 0

//Circular Queue 구조체 선언
typedef struct circularQueue {
    int data[Capacity]; //Array List data 선언
    int front;
    int rear;
} cQueue;

//Circular Queue 관련 함수
cQueue* createCircularQueue();
void enqueue(cQueue* q, int data);
int isFull(cQueue* q);
void showQueue(cQueue* q);
int isEmpty(cQueue* q);
void dequeue(cQueue* q);

cQueue* createCircularQueue() {
    cQueue* pQ = NULL;
    int i;
    //메모리상에 Queue를 할당시키고 이를 반환
    pQ = (cQueue*) malloc(sizeof(cQueue));
    if(pQ == NULL) {
        printf("Memory out!\n");
        return NULL;
    }
    pQ->front = 0;
    pQ->rear = 0;

    return pQ;
}
void showQueue(cQueue* q) {
    int i;
    if(isEmpty(q) == TRUE) {
        printf("Circular Queue is Empty!\n");
        return;
    }
    printf("======== show queue ========\n");
    for(i = (q->front+1) % Capacity; i != q->rear; i = (i+1)%Capacity) printf("[%d]\n", q->data[i]);
    printf("[%d]\n", q->data[i]);
    printf("============================\n");
}

void enqueue(cQueue* q, int data) {
    if(isFull(q) == TRUE) {
        printf("Circular Queue is full!\n");
        return;
    }
    //Circular Queue 뒷 부분에 data를 추가
    q->rear = (q->rear+1) % Capacity;
    q->data[q->rear] = data;
}
void dequeue(cQueue* q) {
    if(isEmpty(q) == TRUE) {
        printf("Circular Queue is Empty!\n");
        return;
    }
    // Circualr Queue의 앞 부분을 다음 칸으로 이동
    q->front = (q->front+1) % Capacity;
}

int isFull(cQueue* q) {
    if((q->rear+1) % Capacity == q->front) return TRUE;
    else return FALSE;
}
int isEmpty(cQueue* q) {
    if(q->front == q->rear) return TRUE;
    else return FALSE;
}

int main() {
    cQueue* q;
    //Circular Queue 초기화
    q = createCircularQueue();
    printf("front:%d, rear:%d\n", q->front, q->rear);

    printf("enqueue data 10\n");
    printf("enqueue data 20\n");
    printf("enqueue data 30\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    showQueue(q);
    printf("front:%d, rear:%d\n", q->front, q->rear);

    printf("dequeue\n");
    printf("dequeue\n");
    dequeue(q);
    dequeue(q);
    showQueue(q);
    printf("front:%d, rear:%d\n", q->front, q->rear);

    printf("enqueue data 40\n");
    enqueue(q, 40);
    printf("front:%d, rear:%d\n", q->front, q->rear);
    printf("enqueue data 50\n");
    enqueue(q, 50);
    printf("front:%d, rear:%d\n", q->front, q->rear);
    printf("enqueue data 60\n");
    enqueue(q, 60);
    showQueue(q);
    printf("front:%d, rear:%d\n", q->front, q->rear);
    printf("enqueue data 70\n");
    enqueue(q, 70);
    printf("front:%d, rear:%d\n", q->front, q->rear);
    showQueue(q);
    free(q);
    return 0;
}