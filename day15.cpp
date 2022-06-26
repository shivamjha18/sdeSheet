//bottomview
vector<int> bottomView(BinaryTreeNode<int> * root){

    map<int,int>mp;
    queue<pair<BinaryTreeNode<int> *,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        BinaryTreeNode<int> *temp=it.first;
        int a=it.second;
        q.pop();
        mp[a]=temp->data;
        if(temp->left){
            q.push({temp->left,a-1});
        }
        if(temp->right){
            q.push({temp->right,a+1});
        }
    }
    vector<int>v;
    for(auto it:mp){
        v.push_back(it.second);
    }
    return v;
    
}
//verticalordertraversal
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
	if(root==NULL)
		return {};
	queue<pair<TreeNode<int> *,int>> q;
	map<int,vector<TreeNode<int>*>> mp;
	mp[0].push_back(root);
	q.push({root,0});
	while(!q.empty())
	{
		int n=q.size();
		int i=0;
		while(i<n)
		{
			pair<TreeNode<int> *,int> p=q.front();
			if(p.first->left!=NULL)
			{
			    q.push({p.first->left,p.second-1});
					mp[p.second-1].push_back(p.first->left);
			}
			if(p.first->right!=NULL)
			{
				q.push({p.first->right,p.second+1});
					mp[p.second+1].push_back(p.first->right);
			}
			q.pop();
			i++;
		}
	}
	vector<int> ans;
	for(auto it:mp)
	{
		int n=(it.second).size();
		vector<TreeNode<int> *> temp=(it.second);
		int i=0;
		while(i<n)
		{
			ans.push_back(temp[i]->data);
			i++;
		}
	}
	return ans;
}

//lca
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(root == NULL) return -1;
    if(root->data == x || root->data == y) return root->data;
    int left=lowestCommonAncestor(root->left, x, y);
    int right=lowestCommonAncestor(root->right, x, y);
    if(left == -1){
        return right;
    }
    else if(right == -1) {
        return left;
    }
    else {
        return root->data;
    }
}

//height using inorder and level
#include<bits/stdc++.h>
typedef struct Node
{
    int height;
    int left;
    int right;
}
Node;
int heightOfTheTree(vector<int>& inorder, vector<int>& level, int N)
{
   queue<Node> q;
    Node it;
    
    it.height=0;
    it.left=0;
    it.right=N-1;
    
    q.push(it);
    int pos[N+1];
    for(int i=0;i<N;i++)
    {
        pos[inorder[i]]=i;
    }
    
    int mxheight=0;
    
    for(int i=0;i<N;i++)
    {
        int curr=level[i];
        
        Node now=q.front();
        q.pop();
        
        int currPos=pos[curr];
        
        //left child Present
        if(currPos>now.left)
        {
            Node newNode;
            
            newNode.height=now.height+1;
            mxheight=max(mxheight,newNode.height);
            newNode.left=now.left;
            newNode.right=currPos-1;
            
            q.push(newNode);
        }
        if(currPos<now.right)
        {
            Node newNode;
            
            newNode.height=now.height+1;
            mxheight=max(mxheight,newNode.height);
            newNode.left=currPos+1;
            newNode.right=now.right;
            
            q.push(newNode);
        }
    }
   return mxheight;
}
//connect same level
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode< int > *>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
       for(int i=0;i<n;i++){
            BinaryTreeNode< int > *temp=q.front();
            q.pop();
            if(i==n-1){
                temp->next=NULL;
                
            }
            else{
                
                temp->next=q.front();
            }
  
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
         
        }
    }
}

//bst to doubly
void inorder(BinaryTreeNode<int>* root,vector<int>&res)
{
    if(root==NULL)
        return;
    inorder(root->left,res);
    res.push_back(root->data);
    inorder(root->right,res);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<int>res;
    inorder(root,res);
    BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* t=newnode;
    for(int i=0;i<res.size();i++)
    {
     newnode->right=new BinaryTreeNode<int>(res[i]);
        BinaryTreeNode<int>* x=newnode->right;
         x->left=newnode;
         newnode=newnode->right;
    }
    return t->right;
}

