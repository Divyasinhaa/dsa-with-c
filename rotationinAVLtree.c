#include <stdio.h>
#include <malloc.h>
struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
};