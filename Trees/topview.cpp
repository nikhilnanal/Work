// This is a qualified hacker rank challenge

/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
void printleft(node* root){
    if (!root){
        return;
    }
    else if (root->left!=NULL){
        printleft(root->left);
    }
    printf("%d ",root->data);
}
void printright(node* root){
    if (!root){
        return;
    }
    printf("%d ",root->data);
    if (root->right!=NULL){
        printright(root->right);
    }
    
}

void top_view(node * root)
{
    if(!root){
        return;
    }else{
    printleft(root->left);
    //if (root)
     printf("%d ",root->data);
    printright(root->right);
    }
}
