/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
#include<stack>

node * lca(node * root, int v1,int v2)
{

    stack<node*> st;
    node * temp1;
    node* temp2;
    if (!root){
        return NULL;
    }
    else{
        st.push(root);
        temp1 =root;
        while ((temp1->data!=v1)||temp1!=NULL){
            if (temp1->data > v1){
                temp1=temp1->left;
                st.push(temp1);
            }
            else if(temp1->data<v1){
                temp1=temp1->right;
                st.push(temp1);
            }
            else{
                break;
            }
            
       }
        while (!st.empty()){
            
            temp2 = st.top();
             while ((temp2!=NULL) || (temp2->data!=v2)){
                  if (temp2->data >v2){
                      temp2=temp1->left;
                  }
                 else if(temp2->data<v2){
                       temp2=temp2->right;
                 }
                 else if (temp2->data==v2){
                     return st.top();
                 }
                 else{
                     st.pop();
             
                 }
                     
             }
        }
   }
        


 return NULL;  
}

