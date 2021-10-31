enum bool{
    false,true
};

//for each node datatype;
typedef struct node1{  
int data;
struct node1*next;
}node;
node*head=NULL;
node*tail = NULL;
 

node* create_node(int data);

void enqueue(int data);

int dequeue();

void print_queue();