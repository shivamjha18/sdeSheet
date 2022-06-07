//1-unique elements
int uniqueElement(vector<int> arr, int n)
{
    int xo=0; 
	for(int i=0;i<n;i++){
        xo=xo^arr[i];
    }
    return xo;
}

//2-print permutation
void solve(string s,vector<string>&ans,int ind){
    if(ind==s.size()){
        ans.push_back(s);
    }
    for(int j=ind;j<s.size();j++){
        swap(s[j],s[ind]);
        solve(s,ans,ind+1);
        swap(s[j],s[ind]);
   }
}
vector<string> findPermutations(string &s) {
    int index=0;
    vector<string>ans;
    solve(s,ans,index);
    return ans;
}

//3-kth max and min
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>pq1;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        int a=pq.top();
        if(a>arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int>v;
    v.push_back(pq.top());
     for(int i=0;i<k;i++){
        pq1.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        int a=pq1.top();
        if(a<arr[i]){
            pq1.pop();
            pq1.push(arr[i]);
        }
    }
    v.push_back(pq1.top());
    return v;
}
//4-inorder
oid solve(TreeNode *root,vector<int>&v){
    if(root==NULL){
        return;
    }
        solve(root->left,v);
        v.push_back(root->data);
        solve(root->right,v);
    
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>v;

    solve(root,v);
    return v;
}

//5-preorder
void solve(TreeNode *root,vector<int>&v){
    if(root==NULL){
        return;
    }
      
        v.push_back(root->data);
        solve(root->left,v);
        solve(root->right,v);
    
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>v;
    solve(root,v);
    return v;
}

//6-post
void solve(TreeNode *root,vector<int>&v){
    if(root==NULL){
        return;
    }
      
        
        solve(root->left,v);
        solve(root->right,v);
    v.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>v;
    solve(root,v);
    return v;
}
//7-left view
vector<int> getLeftView(TreeNode<int> *root)
{
    if(root==NULL)

   {

       return {};

   }
    queue<TreeNode<int>*>q;
    q.push(root);
    vector<int>v;
    while(!q.empty()){
        int n=q.size();
       while(n--){
           TreeNode<int>*node=q.front();
           q.pop();
           if(n==0){
               v.push_back(node->data);
           }
           if(node->right){
               q.push(node->right);
           }
           if(node->left){
               q.push(node->left);
           }
       }
    }
    return v;
}
