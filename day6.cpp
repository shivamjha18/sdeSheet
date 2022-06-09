//1-pattern matching
bool findPattern(string p, string s)
{
    int n=s.size();
    int k=p.size();
    for(int i=0;i<n;i++){
        if(p==s.substr(i,k)){
            return true;
        }
    }
    return false;
}

//2-check permutation/anagram

#include<bits/stdc++.h>
bool areAnagram(string &str1, string &str2){
    map<char,int>mp;
    int n=str1.size(),m=str2.size();
    for(int i=0;i<n;i++){
        mp[str1[i]]++;
    }
    for(int i=0;i<m;i++){
        mp[str2[i]]--;
    }
    for(auto it:mp){
        if(it.second){
            return false;
        }
    }
    return true;
                        
}
// 3-pre,post,in
void inorder(BinaryTreeNode<int> *root,vector<int>&in)
{
    if(root==NULL)
        return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
    return;
}
void preorder(BinaryTreeNode<int> *root,vector<int>&pre)
{
    if(root==NULL)
        return;
    pre.push_back(root->data);
    preorder(root->left,pre);
    preorder(root->right,pre);
    return;
}
void postorder(BinaryTreeNode<int> *root,vector<int>&post)
{
    if(root==NULL)
        return;
    postorder(root->left,post);
    postorder(root->right,post);
    post.push_back(root->data);
    return;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> arr;
    vector<int>in;
    vector<int>pre;
    vector<int>post;
    inorder(root,in);
    preorder(root,pre);
    postorder(root,post);
    arr.push_back(in);
    arr.push_back(pre);
    arr.push_back(post);
    return arr;
}
//4-level order traversal

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    queue<BinaryTreeNode<int>*>q;
    if(root==NULL) return ans;

   q.push(root);

   while(!q.empty()){

       BinaryTreeNode<int>* front=q.front();

       ans.push_back(front->val);

       q.pop();

       if(front->left!=NULL) q.push(front->left);

       if(front->right!=NULL) q.push(front->right);

   }

   return ans;
    
}

//5-right view
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int>v;
     if(root==NULL)return {};
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            BinaryTreeNode<int>* temp=q.front();
            q.pop();
            if(n==0){
                v.push_back(temp->data);
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
            
        }
    }
    return v;
}
