// Submitted on Hacker-rank

#include <queue>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    
    if (!root){return;}
queue<node*> que;
    
    que.push(root);
    
    while (!que.empty()){
        
        node* temp=que.front();
        printf("%d\t",temp->data);
        que.pop();
     
         
         if (temp->left!=NULL){
             que.push(temp->left);
         }
        if (temp->right!=NULL){
             que.push(temp->right);
        }
       
    }
  
}
