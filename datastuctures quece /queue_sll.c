#include<stdio.h>
#include<stdlib.h>
#include "queue_sll.h"
//singly linked list implementation of queue

//bool for logical user defined datatype;
//for creating node;
node* create_node(int data){
    node*temp = malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}


//for enqueue in the queue;
void enqueue(int data){
    
    if(head==NULL){
        node* temp = create_node(data);
        head = temp;
        tail = temp;
    }
    else{
        node*temp = create_node(data);
        tail->next = temp;
        tail= tail->next;
    }
    
}

//dequeue in the queue;
int dequeue(){

    if(head==NULL){
        printf("queue is empty")
        ;exit(0);
    }else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    
    
    else
    { 
        node* temp = head ;
        head = head->next;
        free(temp);
    }
}
    

//print the queue data;
    // insert(root ,16);
void print_queue(){
    int end =false ;
    node*temp = head;
    while (!(end))
    {
        if(temp ==tail){
            printf("%d \n",temp->data);
            end = true;
        }else{
            printf("%d ",temp->data);
            temp=temp->next;

        }
    }
    
}







int main(int argc, char const *argv[])
{
    enqueue(45);
    print_queue();
printf("___________________________________\n")
    ;enqueue(65);
    print_queue();
printf("________________________________\n");
    dequeue();

    
    print_queue();
    return 0;
}


