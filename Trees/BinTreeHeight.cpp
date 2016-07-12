// This is solved from Hacker-rank
/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/

#define MAX(a,b) ((a)>=(b) ? (a):(b))
int height(node * root)
{
    int treeheight;
  if ((!root) || ((root->left==NULL) &&(root->right==NULL))){
      return 0;
  }
    else{
         int a =height(root->left);
         int b = height(root->right);
        treeheight= (MAX(a,b)) + (1) ;
    }
    return treeheight;
}
