#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//Stack 구조체 선언
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

//Stack 관련 함수
void pushLinkedStack(StackNode** top, int data);
StackNode* popLinkedStack(StackNode** top);
void showLinkedStack(StackNode* top);
StackNode* topLinkedStack(StackNode* top);
void deleteLinkedStack(StackNode** top);
int isEmpty(StackNode* top);

int main() {
    // 가장 윗 부분을 가리키는 top 포인터 선언
    StackNode* top = NULL;
    StackNode* pNode;
    printf("Push(10, 20, 30) called.\n");
    pushLinkedStack(&top, 10);
    pushLinkedStack(&top, 20);
    pushLinkedStack(&top, 30);
    showLinkedStack(top);

    printf("Pop() called.\n");
    pNode = popLinkedStack(&top);
    if(pNode) {
        free(pNode);
        showLinkedStack(top);
    }
    printf("Top() called.\n");
    pNode = topLinkedStack(top);
    if(pNode) printf("The node's data: %d\n", pNode->data);
    else printf("The stack is empty.\n");
    showLinkedStack(top);

    deleteLinkedStack(&top);
    return 0;
}

int isEmpty(StackNode* top) {
    if(top == NULL) return TRUE;
    else return FALSE;
}
void showLinkedStack(StackNode* top) {
    StackNode* pNode = NULL;
    if(isEmpty(top)) {
        printf("the Stack is empty.\n");
        return;
    }
    pNode = top;
    printf("========= Show Stack =========\n");
    while(pNode != NULL) {
        printf("[%d]\n", pNode->data);
        pNode = pNode->next;
    }
    printf("==============================\n");
}
void pushLinkedStack(StackNode** top, int data) {
    StackNode* pNode = NULL;
    
    //넣을 Stack Node를 할당하고 data 값을 저장
    pNode = (StackNode*) malloc(sizeof(StackNode));
    if(!pNode) {
        printf("memory out!\n");
        return;
    }
    if(isEmpty(*top)) {
        pNode->data = data;
        pNode->next = NULL;
        *top = pNode;
    }
    else {
        pNode->data = data;
        pNode->next = *top;
        *top = pNode;
    }
}
StackNode* popLinkedStack(StackNode** top) {
    StackNode *pNode = NULL;
    //Stack이 비어있는지 검사
    if(isEmpty(*top)) {
        printf("The stack is Empty!\n");
        return NULL;
    }
    else {
        pNode = *top;
        *top = (*top)->next;
    }
    return pNode;
}

StackNode* topLinkedStack(StackNode* top) {
    StackNode* pNode = NULL;
    if(!isEmpty(top)) pNode = top;
    return pNode;
}

void deleteLinkedStack(StackNode** top) {
    StackNode* pNode = NULL, *pDelNode = NULL;
    pNode = *top;
    while (pNode != NULL) {
        pDelNode = pNode;
        pNode = pNode->next;
        free(pDelNode);
    }
    *top = NULL;
}