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
    return n;   
};
int bst(struct node * root)
{
    static struct node *prev=NULL;
    
    
    if(root!=NULL){
        if(!bst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return bst(root->right);
    }
    else{
        return 1;
    }

};
int main(){
    struct node*p=createnode(9);
   struct node*p1=createnode(4);
   struct node*p2=createnode(11);
   struct node*p3=createnode(2);
   struct node*p4=createnode(7);
   struct node*p5=createnode(15);
   struct node*p6=createnode(5);
   struct node*p7=createnode(8);
   struct node*p8=createnode(14);

   //link of the pointer node to the struct node
   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   p2->right=p5;
   p4->left=p6;
   p4->right=p7;
   p5->left=p8;

   bst(p); 
   return 0;

}
