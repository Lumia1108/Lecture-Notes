#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct List {
    int size;
    int capacity;
    int* items;
} List;

void initList(List* list, int capacity);
void destroyList(List* list);
bool isEmpty(const List* list);
int size(const List* list);

bool insert(List* list, int value);
bool removeItem(List* list, int value);
void clear(List* list);
void printList(const List* list);

void initList(List* list, int capacity) {
    (*list).items = (int*) malloc(sizeof(int) * capacity);
    (*list).size = 0;
    (*list).capacity = capacity;
    if((*list).items == NULL) printf("Fail: Out of Memory!");
}
void destroyList(List* list) {
    free((*list).items);
}
bool isEmpty(const List* list) {
    return ((*list).size == 0 ? true:false);
}
int size(const List* list) {
    return (*list).size;
}
bool insert(List* list, int value) {
    if((*list).size == (*list).capacity) {
        printf("List is Full!\n");
        return false;
    }
    else {
        (*list).items[(*list).size++] = value;
        return true;
    }
}
bool removeItem(List* list, int value) {
    if(isEmpty(list)) return false; // List가 비어있음.
    else {
        int i = 0;
        while(i < (*list).size && (*list).items[i] != value) {
            i++;
        }
        if(i == (*list).size) return false; // List에 해당 값이 없음
        while(i < ((*list).size - 1)) {
            (*list).items[i] = (*list).items[i + 1];
            i++;
        }
        (*list).size --;
        return true;
    }
}
void clear(List* list) {
    (*list).size = 0;
}
void printList(const List* list) {
    if(isEmpty(list)) return;
    for(int i = 0; i < (*list).size; i++) {
        printf("%d\n", (*list).items[i]);
    }
}

int main() {
    List list;
    initList(&list, 10);
    printf("is empty: %d\n", isEmpty(&list));
    for(int i = 1; i < 12; i++) insert(&list, i);
    printList(&list);
    removeItem(&list, 5);
    printList(&list);
    printf("is empty: %d\n", isEmpty(&list));
    printf("size: %d\n", size(&list));
    clear(&list);
    printf("is empty: %d\n", isEmpty(&list));
    destroyList(&list);
    return 0;
}