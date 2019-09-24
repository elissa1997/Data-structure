#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct SqQueue
{
    ElemType data;
    struct SqQueue *next;
}SqQueue;

SqQueue *initQueue(){
    SqQueue *head = (SqQueue *)malloc(sizeof(SqQueue));
    head -> next = NULL;
    return head;
}

SqQueue *EnQueue(SqQueue *rear, ElemType data){
    SqQueue *enNode = (SqQueue *)malloc(sizeof(SqQueue));
    enNode -> data = data;
    enNode -> next = NULL;
    rear -> next = enNode;
    rear = enNode;
    return rear;
}

SqQueue *OutQueue(SqQueue *front){
    if(front -> next == NULL){
        printf("Queue is empty");
    }else{
        SqQueue *OutQueue = (SqQueue *)malloc(sizeof(SqQueue));
        OutQueue = front -> next;
        printf("%d\n",OutQueue->data);
        front -> next = OutQueue -> next;
        free(OutQueue);
        return front;
    }
}

SqQueue *viewQueue(SqQueue *front){
    SqQueue *view;
    view = front;
    printf("<- ");
    while(view -> next != NULL){
        view = view -> next;
        printf("%d  ",view->data);
    }
    printf(" <-\n");

}

int main(){

    SqQueue *queue,*front,*rear;

    front = rear = queue = initQueue();

    for (int i = 0; i < 15; i++)
    {
        rear = EnQueue(rear,i);
    }

    for (int i = 0; i < 15; i++)
    {
        front = OutQueue(front);
    }
    
    
    viewQueue(queue);



    
    
}