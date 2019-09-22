#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct duLNode
{
    int elem;
    struct duLNode *prior;
    struct duLNode *next;
}duLNode;

int createSrand(int count, int range){
    return rand() % range;
}

int getLength(duLNode *list){
    int length = 0;
    while(list -> next != NULL){
        length++;
    }
    return length;
}

void printLink(duLNode *list){
    duLNode *temp = list;
    while(temp -> next != NULL){
        temp = temp -> next;
        printf("%d  ",temp -> elem);
    }
    printf("\n");
}

duLNode *createLink(){
    duLNode *node, *head, *end;
    head = (duLNode*)malloc(sizeof(duLNode));
    head -> prior = NULL;
    head -> next = NULL;

    end = head;
    for (int i = 0; i < N; i++)
    {
        node = (duLNode*)malloc(sizeof(duLNode));
        node-> elem = createSrand(N, 500);
        end -> next = node;
        node -> prior = end;
        end = end -> next;
        
    }

    end -> next = NULL;
    return head;
}

duLNode *insertLink(duLNode *list){

    duLNode *temp = list;

    duLNode *insert = (duLNode*)malloc(sizeof(duLNode));
    printf("enter value you want to insert\n");
    int value;
    scanf("%d",&value);
    insert -> elem = value;

    printf("enter postion you want to insert\n");
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        temp = temp->next;
        if(temp == NULL){
            printf("postion error!!\n");
        }
    }

    int type;

    printf("choose insert type\n 1. Pre insertion   2.Post insertion\n");
    scanf("%d",&type);
    if(type == 1){

        insert->prior = temp->prior;
        temp->prior->next = insert;
        insert->next = temp;
        temp->prior = insert;

    }else if (type == 2)
    {
    
        insert -> next = temp -> next;
        temp -> next -> prior = insert;
        insert -> prior = temp;
        temp -> next = insert;

    }

}

duLNode *delLink(duLNode *list){
    duLNode *temp = list;

    printf("enter postion you want to delete\n");
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        temp = temp->next;
        if(temp == NULL){
            printf("postion error!!\n");
        }
    }
    temp -> prior ->next = temp -> next;
    temp -> next -> prior = temp -> prior;
    free(temp);
}

duLNode *updateLink(duLNode *list){
    duLNode *temp = list;

    printf("enter postion you want to update\n");
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        temp = temp->next;
        if(temp == NULL){
            printf("postion error!!\n");
        }
    }

    printf("new value is:");
    scanf("%d",&temp->elem);
}


duLNode *selectLink(duLNode *list){
    duLNode *temp = list;
    printf("enter value you want to find\n");
    int value,i;
    i=0;
    scanf("%d",&value);
    while(temp -> next != NULL){
        if(temp -> elem == value){
            printf("%d",i);
            break;
        }
        temp = temp -> next;
        i++;
    }

}


int main(){

    duLNode *p = createLink();
    printLink(p);

    selectLink(p);
}