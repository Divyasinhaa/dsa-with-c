#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    
};
struct node *createnode(int d){
    struct node*n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->left=NULL;
    n->right=NULL;
    return createnode;   
}

int main(){
    /*struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    p->data=2;
    p->left=NULL;
    p->right=NULL;

    struct node*p1;
    p1= (struct node*)malloc(sizeof(struct node));
    p1->data=1;
    p1->left=NULL;
    p1->right=NULL;

    struct node*p2;
    p2= (struct node*)malloc(sizeof(struct node));
    p2->data=11;
    p2->left=NULL;
    p2->right=NULL;
    
    //linking the nodes
    p->left=p1;
    p->right=p2;

    return 0;
    */
   struct node*p=createnode(2);
   struct node*p1=createnode(1);
   struct node*p2=createnode(3);
   
   //link of the pointer node to the struct node
   p->left=p1;
   p->right=p2;

   return 0;

}

