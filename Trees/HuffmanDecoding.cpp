//// This is submitted as a hacker rank challenge

/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    
    int i=0;
    
    if ((root) && (!s.empty())){
    node* temp = root;
        while (i<s.size()){
            
            if ((s[i]=='0') && (temp!=NULL)) {
                  temp=temp->left;
                if ((temp->left==NULL) && (temp->right==NULL)){
                     printf("%c",temp->data);
                     temp=root;
                }
            }
           else if ((s[i]=='1') && (temp!=NULL)) {
                  temp=temp->right;
                if ((temp->left==NULL) && (temp->right==NULL)){
                     printf("%c",temp->data);
                     temp=root;
                }
            }
          i++;          
            
        }
       
        
        
        
                       
    }
    
    
    
}
