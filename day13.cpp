//pair sum equal to k
void inorder(BinaryTreeNode<int> *root, unordered_map<int,int>&mp){
    if(root){
        inorder(root->left,mp);
        mp[root->data]++;
        inorder(root->right,mp);
    }
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
     unordered_map<int,int>mp;
    inorder(root,mp);
    for(auto it:mp){
        int ans=k-it.first;
        mp[it.first]--;
        if(mp.find(ans)!=mp.end() && mp[ans]>=1){
            return true;
        }
        mp[it.first]++;
    }
    return false;
    
}

//largest bst in tree
vector<int> largeBST(TreeNode<int>* root)
{
    if(root==NULL)
        return {0,INT_MAX,INT_MIN};
    vector<int> l=largeBST(root->left);
    vector<int> r=largeBST(root->right);
    //l[0]-size,l[1]-min,l[2]-max
    if(l[2]< root->data && root->data<r[1])
        return {1+l[0]+r[0],min(l[1],root->data),max(r[2],root->data)};
    else
        return {max(l[0],r[0]),INT_MIN,INT_MAX};
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    vector<int> temp=largeBST(root);
    return temp[0];
}

//predecessor and successor
void inorder(BinaryTreeNode<int>* root,vector<int>&v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    vector<int>v;
    pair<int,int>p;
    inorder(root,v);
    for(int i=0;i<v.size();i++){
        if(v[i]==key){
            if(i!=0){
                p.first=v[i-1];
            }
            else{
                p.first=-1;
            }
            if(i!=v.size()-1){
                p.second=v[i+1];
            }else{
                p.second=-1;
            }
        }
    }
    return p;
}

//kth largest in bst
void inorder(TreeNode<int>* root,vector<int>&v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
        
    }
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
   vector<int>v;
    inorder(root,v);
    int n=v.size();
    if(n>=k){
        return v[n-k];
    }
    return -1;
    
}

//nth root of m
double findNthRootOfM(int n, long long m) {
	
   double t=1.000000/n;
    double ans=pow(m,t);
    return ans;
}


