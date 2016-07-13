// There is a much better approach than this using recursion, which exploits the fact that LCA->data lies between v1 and v2
// However, this one iteratively uses a c++ stack class 
// address space stack, in recursion. 
//  The idea here is as you traverse to v1 store the ancestors of v1 in a stack with root being at the bottom of the stack.
//  Then, popping one ancestor of v1 at a time (closest ancestor=parent of v1 is at the top of the stack) from the stack, 
//  traverse down to to either NULL or meet v2. if v2 is met return the top element of the stack. this returned node will be
// the LCA.
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
        
        temp1 =root;
        st.push(temp1);
        while (temp1->data!=v1){
            if (temp1->data > v1){
              
                temp1=temp1->left;
                
            }
            else if(temp1->data<v1){
              
                temp1=temp1->right;
                
            } 
            if (temp1){ st.push(temp1);}
       }
      
        temp2 = st.top();
        while (!st.empty()){       
           // printf("%d\t",temp2->data);
            
             while (temp2->data!=v2){
                  if (temp2->data >v2){
                      temp2=temp2->left;
                  }
                 else if(temp2->data<v2){
                       temp2=temp2->right;
                 }
                if (!temp2){
                    st.pop();
                    temp2 = st.top();
                }
              }
            return st.top();
      }
    }
        

// if nothing is found;
  return NULL;
}
