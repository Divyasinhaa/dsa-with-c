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
struct node * search(struct node * root,int key)
{
    if(root!=NULL){
        if(root->data==key){
            return root;
        }
        else if(root->data>key){
            return search(root->left,key);
        }
        else{
            return search(root->right,key);
        }
    }
    else{
        return root;
    }
};
int main(){
   struct node*p=createnode(4);
   struct node*p1=createnode(1);
   struct node*p2=createnode(6);
   struct node*p3=createnode(5);
   struct node*p4=createnode(2);
   //link of the pointer node to the struct node
   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   struct node *n=search(p,4); 
   if(n!=NULL){
    printf(" found %d",n->data);
   }
   else{
    printf("element not found");
   }
   return 0;

}
