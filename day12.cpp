//ceil of bst
int ceil=-1;
	BinaryTreeNode<int> * cur=node;
	while(cur){
		if(cur->data==x){
			return cur->data;
		}
		if(cur->data>x){
			ceil=cur->data;
			cur=cur->left;
		}
		else cur=cur->right;
	}
	return ceil;

//2-array to bst
TreeNode<int>*f(vector<int>&arr,int l,int h){
    if(l>h) return NULL;
    if(l==h) return new TreeNode<int>(arr[l]);
    int mid=(l+h)/2;
    TreeNode<int>* root=new TreeNode<int>(arr[mid]);
    root->left=f(arr,l,mid-1);
    root->right=f(arr,mid+1,h);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return f(arr,0,n-1);
    
}