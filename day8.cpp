//1-isbst
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL){
        return false;
    }
    while(root){
        if(x==root->data){
            return true;
        }
        else if(x>root->data){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return false;
}
//2-ismirror
bool solve(BinaryTreeNode<int>* root,BinaryTreeNode<int>* root1){
    if(root && !root1 || !root && root1){
        return false;
    }
    if(!root && !root1){
        return true;
    }
    if(root->data!=root1->data){
        return false;
    }
    return solve(root->left,root1->right) && solve(root->right,root1->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
   return solve(root,root);    
}