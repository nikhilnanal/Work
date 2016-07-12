//Submitted on Hacker-rank
/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node * insert(node * root, int value)
{
    if(!root){
        node* newnode =new node;
         newnode->data=value;
          newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }
    else {
           
        if (root->data >= value){
             root->left=insert(root->left,value);
          }
        else if (root->data<value){
             root->right=insert(root->right,value);
        }
    
    }
    
    

   return root;
}
