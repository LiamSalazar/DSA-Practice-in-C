# include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory error\n");
        return NULL;
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void addBegining(struct Node** head, int val){
    struct Node* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

void addEnd(struct Node** head, int val){
    struct Node* newNode = createNode(val);
    struct Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    puts("NULL");
}

void liberateList(struct Node** head){
    while(*head != NULL){
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main(){
    struct Node* lista = NULL;

    // Agregar elementos
    addBegining(&lista, 3);
    addBegining(&lista, 2);
    addBegining(&lista, 1);
    addEnd(&lista, 4);
    addEnd(&lista, 5);

    // Imprimir la lista
    printf("Lista enlazada:\n");
    printList(lista);

    // Liberar memoria
    liberateList(&lista);
    return 0;
}