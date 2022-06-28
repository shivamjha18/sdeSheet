//addition of ll
Node *addTwoNumbers(Node *head1, Node *head2)
{
    int first,second,carry=0;
    Node*temp=new Node(0);
    Node*ans=temp;
    while(head1 || head2 ||carry){
        if(head1){
            first=head1->data;
            head1=head1->next;
        }else{
            first=0;
        }
        if(head2){
            second=head2->data;
            head2=head2->next;
        }
        else{
            second=0;
        }
        int res=first+second+carry;
        ans->next=new Node(res%10);
        ans=ans->next;
        carry=(res/10);
    }
    return temp->next;
}

//flattern
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    
    
    if(!root)return root;
    TreeNode<int> *temp=root;
    TreeNode<int> *ans=temp;
    queue<TreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        
        if(temp->right)
            q.push(temp->right);
        
        if(!q.empty()) temp->right=q.front();
        temp->left=NULL;
 
    }
    return ans;
}