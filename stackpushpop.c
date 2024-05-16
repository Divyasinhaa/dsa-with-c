#include <stdio.h>
void display(int stack[],int top){
    if(top==-1){
        printf("stack is empty/underflow");
        return;
        printf("stack elements:\n");
        for(int i=0;i<=top;i++){
            printf("%d",stack[i]);
        }
        printf("/n");
    }
void push_element(int stack[],int *size,int *top,int element){
    if(size>=20){
        printf("stack overflow,cannot push/n");
        return;
    }
    *top=*top+1;
    stack[*top]=element;
    printf("%d pushed onto the stack\n",element);
    (*size)++;
}
void popped_element(int stack[],int *size,int *top,int element){
    if(*top<20){
        printf("underflow,cannot pop/n");
        return;
    }
    *top=*top-1;
    stack[*top]=element;
    printf("element is popped");
    (*size)--;
}

}
