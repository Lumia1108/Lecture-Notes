#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE -1
#define TRUE 1
typedef struct Node {
    int data;
    struct Node* nextNode;
} Node;

typedef struct LinkedList {
    int curCount; // # of Node in List
    Node headNode;
} LinkedList;

int addNode(LinkedList* pList, int pos, int data);
int removeNode(LinkedList* pList, int pos);
void showNode(LinkedList* pList);
int isEmpty(LinkedList* pList);
int findPos(LinkedList* pList, int data);
void makeEmpty(LinkedList* pList);


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
    return FALSE;
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


int main() {
    int pos;
    LinkedList* linkedList = (LinkedList*) malloc(sizeof(LinkedList));
    linkedList->curCount = 0;
    linkedList->headNode.nextNode = NULL;

    showNode(linkedList);
    addNode(linkedList, 0, 10);
    addNode(linkedList, 5, 100);
    addNode(linkedList, 1, 20);
    addNode(linkedList, 2, 30);
    addNode(linkedList, 1, 50);

    showNode(linkedList);

    removeNode(linkedList, 1);
    showNode(linkedList);

    pos = findPos(linkedList, 30);
    printf("The location of node with data '30' : %d\n", pos);
    makeEmpty(linkedList);
    showNode(linkedList);
    free(linkedList);
    return 0;
}