//1-diameter of tree
int f(TreeNode<int>* root,int& d){
    if(!root) return -1;
    int left=1+f(root->left,d);
    int r=1+f(root->right,d);
    d=max(d,left+r);
    return max(left,r);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int d=0;
    f(root,d);
    return d;
}


//2-zigzag traversal
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(!root)return {};
  
    vector<int>v,v1;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    int c=0;
    while(!q.empty()){
        int n=q.size();
       
        while(n--){
            BinaryTreeNode<int>*temp=q.front();
            q.pop();
            v.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(c&1) reverse(v.begin(),v.end());
        for(auto it:v){
            v1.push_back(it);
        }
        c++;
        v.clear();
    }
    return v1;
}
//3-construct a tree using pre and in
int search(vector<int>v,int k){
    for(int i=0;i<v.size();i++){
        if(v[i]==k){
            return i;
        }
    }
}
TreeNode<int>* tree(vector<int> &inorder,vector<int> &preorder,int inst,int inend,int prest,int preend){
    if(inst>=inend || prest>=preend){
        return NULL;
    }
    int parent=preorder[prest];
    int k=search(inorder,parent);
    TreeNode<int>*tree1=new TreeNode<int>(parent);
    int left1=k-inst;
    tree1->left=tree(inorder,preorder,inst,k,prest+1,prest+left1+1);
    tree1->right=tree(inorder,preorder,k+1,inend,prest+left1+1,preend);
    return tree1;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	return tree(inorder,preorder,0,inorder.size(),0,preorder.size());
}