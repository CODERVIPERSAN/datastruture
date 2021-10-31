#include<stdio.h>
#include<stdlib.h>

//quene using array implementation of queue;

int *queue;
int size =5;
int rear =-1;
int first = -1;

enum bool {false,true};
int isFull();
void enqueue(int data){
    int isfull = isFull();
    if(isfull){
        printf("queue overflow");
    }
     rear++;
    if (rear<size){

    queue[rear]=data;
   
    }
    if(rear==0){
        first=0;
    }
    
}


int is_empty(){
    if(first>rear){
        return true;
    
    }else return false;
}

void dequeue(){
    int isempty = is_empty();
    if (isempty){
        printf("queue underflow");
        exit(0);
    }
    
    first++;


}

void print_queue(int *queue){
    for (int i=first;i<=rear;i++)
    {
        
        printf("[%d--%d]",queue[i],i);

    }

}

int isFull(){
    if ((rear-first)==size){
        return true;
    }
    else return false;

}
void restart(){
    first = -1;
    rear =-1;
}




int main(int argc, char const *argv[])
{
    queue = malloc(size*sizeof(int));
    //enqueue and dequeu
    enqueue(1);
    enqueue(2);
    dequeue();
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print_queue(queue);
    free(queue);
    return 0;
}
