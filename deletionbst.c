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
    
}
void delete(struct node * root,int key)
{
    struct node*prev=NULL;
    struct node*ptr;
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
    
        if(key==root->data){
            return root;
        }
        else if(key<root->data){
            return delete(root->left,key);
        }
        else{
            return delete(root->right,key);
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

