#include <stdlib.h>
#include <stdio.h>

#define ElemType int

typedef struct SqStack
{
    ElemType data;
    struct SqStack *next;
}SqStack;

SqStack *initStack(){
    SqStack *top = (SqStack *)malloc(sizeof(SqStack));
    top -> next = NULL;
    return top;
}

SqStack *pushStack(SqStack *top,ElemType d){
    SqStack *node = (SqStack *)malloc(sizeof(SqStack));
    node -> data = d;
    node -> next = top -> next;
    top -> next = node;
}

SqStack *popStack(SqStack *top){
    SqStack *popNode;
    popNode = top -> next;
    if(popNode == NULL){
        printf("Stack is empty");
    }else{
        printf("pop elem is %d\n",popNode -> data);
    }
    top -> next = popNode -> next;
    free(popNode);
}

SqStack *printStack(SqStack *top){
    SqStack *view;
    view = top -> next;
    while (view != NULL)
    {
        printf("  | %-2d|\n",view->data);
        view = view -> next;
    }
    free(view);
    
}

int main(){

    SqStack *stack = initStack();

    for (int i = 0; i < 10; i++)
    {
        pushStack(stack,i);
    }

    for (int i = 0; i < 10; i++)
    {
        popStack(stack);
        printStack(stack);

    }

    printStack(stack);
    
}
