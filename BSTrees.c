#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
 int data;
 struct Node* left;
 struct Node* right;
} Node;


Node* TreeInsert(Node* root, int x){

// Node* newnode =malloc(sizeof(Node));
// newnode->data=x;
// newnode->left=newnode->right=NULL;


if (root == NULL){

 Node* newnode =malloc(sizeof(Node));
 newnode->data=x;
 newnode->left=newnode->right=NULL;
 root=newnode;
 // printf("Now Inserted %d in tree\n",root->data);
}
else {
 // Node* temp =root;
  if (x<root->data){
     root->left=TreeInsert(root->left,x);
    }
 else if(x>root->data){
    root->right=TreeInsert(root->right,x);
    }
else{
    printf("This is a duplicate key, not inserted\n");
    }
}
return root;

}
void Inorder(Node* root){

if (!root){return;}
else{

   if (root->left!=NULL){
      Inorder(root->right);
  }
}

}


int main(){

Node* root=NULL;

int N;
int A[10];

printf("Enter the number of elements:\n");
scanf("%d\n",&N);
int i=0;
while (i<N){
 scanf("%d",&A[i]);
 i++;
}
for (i=0;i<N;i++){
 root= TreeInsert(root,A[i]);
}

Inorder(root);
printf("Now lets Try Deleting\n");
printf("Enter a Number to delete\n");

}



