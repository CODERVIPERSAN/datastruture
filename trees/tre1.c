#include<stdio.h>
#include<stdlib.h>
//basic binary tree

//travasel

typedef struct node{  
int data;
struct node*left;
struct node*right;
}node;

enum bool{
    false,true
};
int isThere=false;
void traversal(node*,int);

void  search(node*ptr,int key){
    if(ptr==NULL){
        return; 
    }
    if(ptr->data==key){
        isThere =true;
    }

    // traversal(ptr->left,0);
    search(ptr->left,key);
    // else if(key!=ptr->data){
    //     isThere = false;
    // }
    // traversal(ptr->right,0);
    search(ptr->right,key);
}
// re is the parameter consist of info  0for inorder ,1 for pre ,2for post;  
void traversal(node*ptr,int re){

   if(ptr==NULL){
       return;
   }

   if(re==0){

    traversal(ptr->left,0);
    printf("%d ",ptr->data);
    traversal(ptr->right,0);
   }
   else if (re==1)
   {
    
   printf("%d ",ptr->data); 
   traversal(ptr->left,1);
   traversal(ptr->right,1);   
       
   }
   else if(re==2){
  
   traversal(ptr->left,2);
   traversal(ptr->right,2);
   printf("%d ",ptr->data); 
  
  
   }
   
   
}


node*add_data(node*temp);


node*create(){
    int choice ;
    node*temp =malloc(sizeof(node));
    temp->left = NULL;
    temp->right =NULL;
    printf("press 0 to exit ");

    printf("press 1 for new node \n");

    printf("Enter the choice \n");

    scanf("%d",&choice);
    if(choice==0){
        return NULL;
    }
    else if (choice ==1)/* condition */
    {
        return add_data(temp);
        }
    }

    




node *add_data(node* temp){
    int data;
    printf("Enter the data ");
    scanf("%d",&data);

    temp->data=data; 

    printf("enter the left child of %d\n",data);

    
    temp->left =create();
    
    printf("enter the right child of the %d\n",data);

    temp->right =create();
    
    return temp;
}


// void main(int argc, char const *argv[])
// {
//     node*root = create();
//     traversal(root,0);

//     // printf("%d",search(root));
//      search(root,7);
//     if (isThere)
//     {
//         printf("found ");
//     }
//     else {
//         printf("not found");
//     }
    
// }








