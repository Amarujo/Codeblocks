#include <stdio.h>
#include <stdlib.h>

struct Node{
        int data;
        Node* next;
    };

struct Node* head;

void Insert(int x);
void Print();

int main(){
    head = NULL;
    printf("%d",head);
    printf("How many numbers: ");
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i ++){
        printf("Enter the number: ");
        scanf("%d", &i);
        Insert(i);
        Print();
    }
}

void Insert(int x){
    Node* temp = (Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
}

void Print(){
}
