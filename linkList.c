#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


typedef struct Link
{
    int elem;
    struct Link *next;
    
}link;

int createSrand(int count, int range){
    return rand() % range;
}

link *creatLink(){

    link *head, *node, *end;
    head = (link*)malloc(sizeof(link));
    end = head;
    for(int i=0; i<N; i++){
        node = (link*)malloc(sizeof(link));
        node->elem = createSrand(N, 50);
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;

}

void printLink(link *list){
    link *temp = list;
    printf("\nlink-table is\n");
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("%d ",temp->elem);
    }
    printf("\n");
    
}

int getLength(link *list){
    int length = 0;
    while (list -> next != NULL){
        length++;
    }
    return length;
}


link *insertLink(link *list){
    link *temp = list;
    //判断数据合法性
    printf("enter postion you want to insert\n");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        if(temp == NULL){
            printf("postion error!!\n");
        }
        temp = temp->next;
    }
    link *insert = (link*)malloc(sizeof(link));
    printf("enter insert value\n");
    scanf("%d",&insert->elem);
    insert->next = temp->next;
    temp->next = insert;
    
}

link *delLink(link *list){
    link *temp = list;
    printf("enter postion you want to delete\n");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n-1; i++){
        //被删除的前一个node
        temp = temp->next;
    }
    link *del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

link *updateLink(link *list){
    link *temp = list;
    printf("enter postion you want to update\n");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        temp = temp->next;
    }
    printf("insert update value\n");
    scanf("%d",&temp->elem);
}

link *selectLink(link *list){
    link *temp = list;
    printf("enter value you want to find\n");
    int value;
    scanf("%d",&value);
    for(int i=0; temp -> next != NULL; i++){
        temp = temp -> next;
        if (temp->elem == value)
        {
            printf("%d in %d,address is 0x%x\n",value,i,temp);
        }
        
    }
}


int main(){

    link *p = creatLink();
    printf("random link-table is\n");
    printLink(p);

    printf("select your option\n");
    printf("1. insert value\n2. delete value\n3. change value\n4. query value\n");
    int menu;
    scanf("%d",&menu);
    switch (menu)
    {
    case 1:
        insertLink(p);
        printLink(p);
        break;
    case 2:
        delLink(p);
        printLink(p);
        break;
    case 3:
        updateLink(p);
        printLink(p);
        break;
    case 4:
        selectLink(p);
        break;
    case 5:
        createSrand(10,50);
        break;
    default:
        break;
    }

    
}

