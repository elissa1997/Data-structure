#include <stdlib.h>
#include <stdio.h>
#define TElemType int
#define NewSpace (BiNode *)malloc(sizeof(BiNode))

typedef struct BiNode{
    TElemType data;
    BiNode *lchild, *rchild;
}BiNode, *BiTree;

BiTree initBiTree(){
    BiTree T;
    T = NewSpace;
    T -> data = 1;
    T -> lchild = NewSpace;
    T -> rchild = NewSpace;
    T -> lchild -> data = 2;
    T -> rchild -> data = 3;
    T -> rchild -> lchild = NULL;
    T -> rchild -> rchild = NULL;
    T -> lchild -> lchild = NewSpace;
    T -> lchild -> rchild = NewSpace;
    T -> lchild -> lchild -> data = 4;
    T -> lchild -> lchild -> lchild = NULL;
    T -> lchild -> lchild -> rchild = NULL;
    T -> lchild -> rchild -> data = 5;
    T -> lchild -> rchild -> lchild = NewSpace;
    T -> lchild -> rchild -> rchild = NewSpace;
    T -> lchild -> rchild -> lchild -> data = 6;
    T -> lchild -> rchild -> lchild -> lchild =NULL;
    T -> lchild -> rchild -> lchild -> rchild =NULL;
    T -> lchild -> rchild -> rchild -> data = 7;
    T -> lchild -> rchild -> rchild -> lchild = NULL;
    T -> lchild -> rchild -> rchild -> rchild = NULL;

    return T;
}

void preOrderTraversal(BiTree root){
    if(root != NULL){
        printf("%d ",root -> data);
        preOrderTraversal(root->lchild);
        preOrderTraversal(root->rchild);
    }
    return;
}

void inOrderTraversal(BiTree root){
    if(root != NULL){
        inOrderTraversal(root->lchild);
        printf("%d ",root -> data);
        inOrderTraversal(root->rchild);
    }
    return;
}

void postOrderTraversal(BiTree root){
    if(root != NULL){
        postOrderTraversal(root->lchild);
        postOrderTraversal(root->rchild);
        printf("%d ",root -> data);
    }
    return;
}

int main(){
    BiTree intTree = initBiTree();
    printf("%d\n",intTree->lchild->lchild->data);
    preOrderTraversal(intTree);
    printf("\n");
    inOrderTraversal(intTree);
    printf("\n");
    postOrderTraversal(intTree);
}