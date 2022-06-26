//partialbst
void inorder(BinaryTreeNode<int> *root,vector<int>&v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
        
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
   vector<int>v;
    inorder(root,v);
    for(int i=1;i<v.size();i++){
        if(v[i]<v[i-1]){
            return false;
        }
    }
    return true;
}

//invert

//bstoterator
class BSTiterator
{
    public: 
    int prev;
    TreeNode<int>* roott;
    BSTiterator(TreeNode<int> *root)
    {
        prev = -1;
        roott = root;
    }

    int next()
    {
        int suc = -1;
        TreeNode<int>* cur = roott;
        while (cur)
        {
            if (cur->data <= prev)
                cur = cur->right;
            else
            {
                suc = cur->data;
                cur = cur->left;
            }
        }
        prev = suc;
        return suc;
    }

    bool hasNext()
    {
        bool hasNext = false;
        int suc = -1;
        TreeNode<int>* cur = roott;
        while (cur)
        {
            if (cur->data <= prev)
                cur = cur->right;
            else if (cur->data > prev)
            {
                suc = cur->data;
                cur = cur->left;
            }
        }
        return (suc != -1);
    }
};

//heap
#include<bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    multiset<int>st;
    vector<int>ans;
    for(auto &it : q){
        if(it[0] == 1){
            auto it = st.begin();
            ans.push_back(*it);
            st.erase(it);
        }else{
            st.insert(it[1]);
            
        }
    }
    return ans;
}
//tree from inorder and postorder
#include<bits/stdc++.h>
TreeNode<int>* makeBT(vector<int>& inOrder, vector<int>& postOrder,int li,int hi,int lp,int hp,map<int,int> &mpp){
    if(lp<0 || lp>hp)return NULL;
// 	cout<<postOrder[hp]<<endl;
    int rootData=postOrder[hp];
    TreeNode<int>* root=new TreeNode<int>(rootData);
    int index = mpp[rootData];
    int numLeft=lp+index-li;
    root->left=makeBT(inOrder,postOrder,li,index-1,lp,numLeft-1,mpp);
    root->right=makeBT(inOrder,postOrder,index+1,hi,numLeft,hp-1,mpp);
    return root;
    
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int n=inOrder.size();
	map<int,int> mpp;
	for(int i=0;i<n;i++){
		mpp[inOrder[i]]=i;
	}
	return makeBT(inOrder,postOrder,0,n-1,0,n-1,mpp);
}