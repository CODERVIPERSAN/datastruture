#include<stdio.h>
#include<stdlib.h>
// #include "datastuctures quece /queue_sll.h"

// extern enqueue()

    // insert(root ,16);
typedef struct node{  
int data;
struct node*left;
struct node*right;
}node;
//binary tree;
//dept order traversal 
extern void traversal(node* ,int);

//level order traversal

// void levelOrder(node* root){
//     if(root ==NULL) return ;
//     queue <node*> Q;
//     Q.push(root);
//     while(!Q.empty())
//     {
//         node*current =Q.front();
//         printf("%d ",current->data)
//         if()

//     }
// }



node*root;
node* new_node(int data){
    node* temp = malloc(sizeof(node));
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;


}



void  insert(node*temp,int data){
    if(temp->data>data){
        if(temp->left==0){
            temp->left = new_node(data);
            return;
        }
        insert(temp->left,data);
        
        
        // return root;
    }
    else if(temp->data<data){
        if(temp->right==0){
            temp->right = new_node(data);
            return ;
        }
        insert(temp->right,data);
        
       
        
        
        
        // return root;
    }

    
    



        // if(temp==0){
        //     return new_node(data);
        // }
        // else if(temp->data>data){
           
        //     if(temp->left==0){
        //     temp->left = new_node(data);
        //     return root;
        //     }
        //      insert(temp->left,data); 
        // }
        // else if(temp->data<data){
            
        //     if(temp->right==0){
        //         temp->right = new_node(data);
        //         return root;
        //      }
        //     insert(temp->right,data);
        // }


    

}
int isthere=0;
void Search(node*temp,int key){
    if(temp==0){
        return ;
    }
    
    if(temp->data == key)isthere = 1;
    else if(!(temp->left==0&&temp->right==0)){
    
    if(temp->data>key) Search(temp->left,key);
    else if (temp->data<key) Search(temp->right,key);

    }
    
}

void message_search(){
    if(isthere){
        printf("found");
    }
    else{
        printf("not found");
    }
}

int lheight,rheight,max;
int Findheight(node*temp){

    if(temp==0){
        return -1;
    }

    lheight = Findheight(temp->left);
    rheight = Findheight(temp->right);

    max = lheight>rheight?lheight:rheight;

    return max+1;


     
}

int Findmin(node*temp){
    if (temp->left==NULL){
        return temp->data;
    }
    return Findmin(temp->left);

    

}
int Min(node*temp){
    return Findmin(temp);
    
}

int Findmax(node*temp){
    if(temp->right==0)return  temp->data;

    Findmax(temp->right);
}
 
int Max(node*temp){
    return Findmax(temp);
}

//deletion operation 
int flag =1;
void  IsBinarySearchTree(node*root){
    node*temp = root;
    if(temp==NULL) return;
    if(!(temp->left<temp)){
        flag =0;
        return ;
    }
    if(!(temp->right>temp)){
        flag=0;
        return;
    }
    

    IsBinarySearchTree(temp->left);
    IsBinarySearchTree(temp->right);

}

node* delete(node* root, int data){
    if(root ==NULL){
        return root;
    }else if(data<root->data) delete(root->left,data);
    else if(data>root->data) delete(root->right,data);
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root =NULL;
            return root;
        }
        else if(root->left == NULL){
            node*temp = root ;
            root = root->right;
            free(temp);
            return root;
            
        }
        else if (root->right ==NULL){

            node*temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else{
            node*temp = Findmin(root->right);
            root->data = temp->data;
            root->right =delete(root->right,temp->data);
            return root;
        }
        
    }
}



int main(int argc, char const *argv[])
{ 
    int data;
int n;
    printf("root node data");
    scanf("%d",&data);
    node*root = new_node(data);

while (1)
{
    

  
    
    printf("1.insertion\n");
    printf("2.print_all\n");
    printf("3.searching\n");
    printf("4.exit\n");
    printf("5.height of the tree\n");
    printf("6.Delete");
    scanf("%d",&n);
    int height;
    switch (n)
    {
    case 1:
    // int data;
        scanf("%d",&data);
        insert(root,data);
        break;

    case 2:
    
    traversal(root,0);

    break;

    case 4:
    printf("\n%d--min\n",Min(root));

    printf("\n %d--max\n",Max(root));
    exit(0);
    break;

    case 3:
  Search(root,4);
 message_search();

  if(flag){
        printf("it is a binary search tree");
    }
    else{
        printf("this is not a binary search tree");
    }
    

    break;
    case 5:
    height = Findheight(root);
    printf("\nheight of the tree %d\n",height);
    break;

    case 6:
    delete(root,data);
    
    break;


    default:
        break;
    }

    // insert (root,data);

    // insert (root,2);

    // insert(root,30);

    // insert(root,4);


    // insert (root,12);
 
    // insert(root ,16);
  

}


    


    // root = insert(root ,data);
    

}
