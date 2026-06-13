#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define CNT 10 // 변수의 개수

/*
코드 설명서
CNT는 변수의 개수입니다.
예를 들어, CNT가 10이면 0부터 9까지 총 10개의 변수를 입력할 수 있습니다.

seq는 Linked List의 배열입니다.
output은 출력했는지 여부를 구분하기 위한 변수입니다.
top은 Linked List로 구현된 스택의 top을 가리키는 포인터입니다.

1=2를 입력하고자 하면, 입력창에
1 2
와 같이 입력하면 되고, 입력을 종료할 때는
-1 -1
을 입력하면 입력이 종료되고 동치 부류가 줄내림(\n)으로 구분되어 출력됩니다.
*/

// Linked List 구조체
typedef struct Node {
    int data;
    struct Node* nextNode;
} Node;

typedef struct LinkedList {
    int curCount; // # of Node in List
    Node headNode;
} LinkedList;

// Stack 구조체
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Linked List 관련 함수
int addNode(LinkedList* pList, int pos, int data);
int removeNode(LinkedList* pList, int pos);
void showNode(LinkedList* pList);
int isEmpty(LinkedList* pList);
int findPos(LinkedList* pList, int data);
void makeEmpty(LinkedList* pList);

//Stack 관련 함수
void pushLinkedStack(StackNode** top, int data);
StackNode* popLinkedStack(StackNode** top);
void showLinkedStack(StackNode* top);
StackNode* topLinkedStack(StackNode* top);
void deleteLinkedStack(StackNode** top);
int isStackEmpty(StackNode* top);


// Linked List 구현
void showNode(LinkedList* pList) {
    int i = 0;
    Node *pNode = NULL;
    if(pList == NULL) {
        printf("showNode() error\n");
        return;
    }
    printf("현재 Node 개수 : %d\n", pList->curCount);
    pNode = pList->headNode.nextNode;
    // pNode가 Linked List 마지막까지 이동하면서 출력
    while(i < pList->curCount && pNode) {
        printf("[%d] \n", pNode->data);
        pNode = pNode->nextNode;
        i++;
    }
    printf("---------------\n");
}
int isEmpty(LinkedList* pList) {
    if(pList == NULL) {
        printf("isEmpty() error\n");
        return -1;
    }
    //if(pList->curCount == 0)
    if(pList->headNode.nextNode == NULL) return TRUE;
    else return FALSE;
}
int findPos(LinkedList* pList, int data) {
    int pos = 0;
    Node* pNode = NULL;
    if(pList == NULL) {
        printf("findPos() error\n");
        return FALSE;
    }
    pNode = pList->headNode.nextNode;
    //마지막 노드까지 탐색
    while(pNode) {
        if(pNode->data == data) return pos;
        pNode = pNode->nextNode; pos++;
    }
    return -1;
}
void makeEmpty(LinkedList* pList) {
    Node* pDummyNode = NULL, *pTmpNode = NULL;
    if(pList != NULL) {
        pTmpNode = pList->headNode.nextNode;
        // 연결되어 있는 모든 노드들을 탐색
        while(pTmpNode) {
            //DummyNode는 지우기 위한 노드
            //TmpNode는 이동하기 위한 노드
            pDummyNode = pTmpNode;
            pTmpNode = pTmpNode->nextNode;
            free(pDummyNode);
        }
        pList->curCount = 0; pList->headNode.nextNode = NULL;
    }
}
int addNode(LinkedList* pList, int pos, int data) {
    int i = 0;
    Node* pNewNode = NULL, *pTmpNode = NULL;
    if(pList == NULL) {
        printf("addNode() error1\n");
        return FALSE;
    }
    if(pos < 0 || pos > pList->curCount) {
        printf("addNode() error2: 추가 범위 초과 \n");
        return FALSE;
    }
    pNewNode = (Node*) malloc(sizeof(Node));
    if(!pNewNode) {
        printf("addNode() error3\n");
        return FALSE;
    }
    pNewNode->data = data;
    pNewNode->nextNode = NULL;

    //추가될 위치 직전 노드로 이동
    pTmpNode = &(pList->headNode);
    for(i = 0; i < pos; i++) {
        pTmpNode = pTmpNode->nextNode;
    }
    //추가 노드의 nextNode = 직전 노드의 nextNode
    //직전 노드의 nextNode = 추가 노드의 주소
    pNewNode->nextNode = pTmpNode->nextNode;
    pTmpNode->nextNode = pNewNode;
    pList->curCount++;
    return TRUE;
}
int removeNode(LinkedList* pList, int pos) {
    int i = 0;
    Node* pDelNode = NULL, *pTmpNode = NULL;
    if(pList == NULL) {
        printf("removeNode() error1\n");
        return FALSE;
    }
    if(pos < 0 || pos >= pList->curCount) {
        printf("removeNode() error2: 삭제 범위 초과\n");
        return FALSE;
    }
    //삭제할 노드 직전 위치로 이동
    pTmpNode = &(pList->headNode);
    for(i = 0;i < pos; i++) pTmpNode = pTmpNode->nextNode;

    //삭제할 노드 = 직전 노드의 nextNode
    //직전 노드의 nextNode = 삭제할 노드의 nextNode
    pDelNode = pTmpNode->nextNode;
    pTmpNode->nextNode = pDelNode->nextNode;
    free(pDelNode);
    pList->curCount--;
    return TRUE;
}

// Stack 구현
int isStackEmpty(StackNode* top) {
    if(top == NULL) return TRUE;
    else return FALSE;
}
void showLinkedStack(StackNode* top) {
    StackNode* pNode = NULL;
    if(isStackEmpty(top)) {
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
    if(isStackEmpty(*top)) {
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
    if(isStackEmpty(*top)) {
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
    if(!isStackEmpty(top)) pNode = top;
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


int output[CNT]; // 출력 여부 저장
LinkedList* seq[CNT]; // Linked List 배열
StackNode* top = NULL; // 스택

// 동치 부류 출력하는 함수
void printEq() {
    for(int i = 0; i < CNT; i++) {
        if(output[i] == FALSE) {
            printf("%d ", i); output[i] = TRUE;
            Node* j = seq[i]->headNode.nextNode;
            while(!(j == NULL && isStackEmpty(top))) {
                if(j == NULL) {
                    StackNode* k = popLinkedStack(&top);
                    j = seq[k->data]->headNode.nextNode;
                    free(k);
                    continue;
                }
                if(output[j->data] == FALSE) {
                    printf("%d ", j->data); output[j->data] = TRUE;
                    pushLinkedStack(&top, j->data);
                }
                j = j->nextNode;
            }
            printf("\n"); // 줄 내림으로 동치 부류를 구분함
        }
    }
}

int main() {
    for(int i = 0; i < CNT; i++) { // output 배열 초기화
        output[i] = FALSE;
    }
    for(int i =0; i < CNT; i++) { // seq 배열 초기화
        LinkedList* linkedList = (LinkedList*) malloc(sizeof(LinkedList));
        linkedList->curCount = 0;
        linkedList->headNode.nextNode = NULL;
        seq[i] = linkedList;
    }
    printf("동치 쌍을 입력하세요. (띄어쓰기로 구분, 변수의 0부터 %d까지 입력 가능, -1 -1 입력 시 종료)\n", CNT - 1);
    // 1 3 을 입력하면 동치 쌍 (1, 3)을 입력한 것.
    int x, y;
    scanf("%d %d", &x, &y);
    while(!(x < 0 || y < 0)) {
        if(x >= CNT || y >= CNT) {
            printf("입력 가능 범위 초과로 입력을 종료합니다.\n");
            break;
        }
        if(findPos(seq[x], y) < 0) addNode(seq[x], 0, y);
        if(findPos(seq[y], x) < 0) addNode(seq[y], 0, x);
        scanf("%d %d", &x, &y);
    }
    printf("\n");
    printEq();
    for(int i = 0; i < CNT; i ++) {
        while (!isEmpty(seq[i])) {
            removeNode(seq[i], 0);
        }
        free(seq[i]);
    }
    return 0;
}