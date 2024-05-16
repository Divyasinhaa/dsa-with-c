#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//used for the recursive
struct node *createnode(int d){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=d;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void postorder(struct node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

int main(){
    struct node *t=createnode(4);
    struct node *t1=createnode(1);
    struct node *t2=createnode(6);
    struct node *t3=createnode(5);
    struct node *t4=createnode(2);

    //linking the tree
    t->left=t1;
    t->right=t2;
    t1->left=t3;
    t1->right=t4;

    //calling the function
    postorder(t);

}