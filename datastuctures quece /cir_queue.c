#include<stdio.h>
#include<stdlib.h>
#define max 6

int arr[6],front=-1,rear=-1;

void enqueue(int data){
        // arr[rear]=data;

    if((rear+1)%max==front){
        printf("Overflow");
        exit(0);
    }
    else if (front==-1&&rear==-1){
        front++;
        rear++;
        arr[rear]=data;
    }
    else{
        // printf("%d",rear);
        rear = (rear+1)%max;
        arr[rear]=data;
    }

    
}

int dequeue(){
    // printf("{%d_f}",front);
    // printf("{%d_r}",rear);
    if(front==-1){
        printf("under flow");
        exit(0);
    }else if(front==rear){
        front =-1;
        rear =-1;

    }else{
        // printf("hello");
        front=(front+1)%max;

        // printf("this");
    }
}





void print_cq(){
    // printf("working");
    if(rear==-1){
        // printf("hello");
        return ;
    }
    else if(front>rear){
// printf("hello");
        int i=front;
        for(;(i%6)!=rear;i++)
        {
            
            printf("%d ",arr[i]);
            
        }
        printf("%d\n",arr[rear]);
    }
    
    else{
        int temp = front;
        // printf("helow");
        // printf("%d",temp);
        for(int i=temp;i<=rear;i++){
            printf(" %d ",arr[i]);
        }
        printf("\n"); 
    }
}


int main(int argc, char const *argv[])
{
    enqueue(45);
    enqueue(55);
    enqueue(65);
    enqueue(75);
    enqueue(85);
    enqueue(90);

    dequeue();
    enqueue(45);
    print_cq();
    dequeue();
    print_cq();
    dequeue();
    dequeue();

    print_cq()
;    
    return 0;
}


