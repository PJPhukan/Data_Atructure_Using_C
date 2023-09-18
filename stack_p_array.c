#include <stdio.h>
#include <stdlib.h>
#define MAX 6
void Push(int a[], int item);
void Pop(int a[]);
void Peek(int a[]);
void Display(int a[]);
int Searching(int a[],int item);
int top = -1;
int main()
{
    int arr[MAX];
    Push(arr,9);
    Push(arr,23);
    Push(arr,8);
    Push(arr,10);
    Push(arr,11);
    Push(arr,12);
    Searching(arr,12);
    Searching(arr,2);
    // Display(arr);
    // Pop(arr);
    // Peek(arr);
    // Display(arr);
    return 0;
}
int Searching(int a[],int item){
    if(top==-1){
        printf("Stack is underflow");
        exit(0);
    }
    else{
        for(int i=0;i<=top;i++){
            if(a[i]==item){
                printf("Item found at the position %d th\n",i+1);
                return 0;
            }
        }
        printf("Item not found");
    }
}
void Push(int a[], int item)
{
    if (top == (MAX - 1))
    {
        printf("Stack is overflow");
        exit(0);

    }
    else
    {
        top++;
        a[top] = item;
    }
}

void Pop(int a[])
{
    int p;
    if(top==-1){
        printf("Stack is underflow");
        exit(0);
    }
    else{
        p=a[top];
        top--;
        printf("Popped element is : %d\n",p);

    }
}

void Peek(int a[])
{
    if(top==-1){
        printf("Stack is underflow");
        exit(0);
    }
    else{
        printf("Peek element is %d\n",a[top]);
    }
}

void Display(int a[])
{
     if(top==-1){
        printf("Stack is underflow");
        exit(0);

    }
    else{
        for(int i=top;i>=0;i--){
            printf("  %d  \n",a[i]);
        }
    }
    
}