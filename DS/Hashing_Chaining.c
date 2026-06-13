#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10
#define TABLE_SIZE 5
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

typedef struct Element {
    char key[KEY_SIZE];
} Element;

typedef struct ListNode {
    Element item;
    struct ListNode *link;
} ListNode;

ListNode *hashTable[TABLE_SIZE];

void initTable(ListNode* ht[]) {
    int i;
    for(i = 0; i < TABLE_SIZE; i++) {
        ht[i] = NULL;
    }
}

int transform(char *key) {
    int i;
    int number = 0;
    int size = strlen(key);
    for(i = 0; i<size; i++) {
        number = number + key[i];
    }
    return number;
}

int hashFunction(char *key) {
    return transform(key) % TABLE_SIZE;
}

void addHashTable(Element item, ListNode* ht[]) {
    int hashValue = hashFunction(item.key);
    ListNode *ptr;
    ListNode *node = ht[hashValue];
    for(; node; node = node->link) {
        if(equal(node->item, item)) return;
    }
    ptr = malloc(sizeof(ListNode));
    ptr->item = item;
    ptr->link = ht[hashValue];
    ht[hashValue] = ptr;
}

void hashSearch(Element item, ListNode* ht[]) {
    ListNode *node;
    int hashValue = hashFunction(item.key);
    for(node = ht[hashValue]; node; node = node->link) {
        if(equal(node->item, item)) {
            printf("탐색 성공: 존재합니다\n");
            return;
        }
    }
    printf("탐색 실패\n");
}
void printHashTable(ListNode* ht[]) {
    int i;
    ListNode *temp;
    for(i = 0; i < TABLE_SIZE; i++) {
        temp = ht[i];
        while(temp) {
            printf("%s ", temp->item.key);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main() {
    Element temp;
    int op;

    while(1) {
        printf("연산 입력(0: 추가, 1: 탐색, 2: 출력, 3: 종료) = ");
        scanf("%d", &op);
        if(op == 3) break;
        if(op == 2) printHashTable(hashTable);
        else {
            printf("키 입력: ");
            scanf("%s", temp.key);
            if(op == 0) addHashTable(temp, hashTable);
            else if(op == 1) hashSearch(temp, hashTable);
        }
    }
    return 0;
}