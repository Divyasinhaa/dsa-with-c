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

struct node *search(struct node*root,int key){
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
};
void insert(struct node * root,int key)
{
    struct node*prev=NULL;
    struct node*ptr;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            return root;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node*new=createnode(key);
    if(key<prev->data){
        prev->left=key;
    }
    else{
        prev->right=key;
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
   insert(p,8); 
    printf("%d",p->right->right->data);
   return 0;

}
