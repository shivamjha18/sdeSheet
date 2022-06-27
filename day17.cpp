//1-reverse ll
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *next;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

//merge two sorted ll
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    
    Node<int>*temp=new Node<int>(-1);
    Node<int>*curr=temp;
    while(first && second){
        if(first->data>second->data){
            temp->next=second;
            temp=temp->next;
            second=second->next;
        }
        else{
             temp->next=first;
            temp=temp->next;
            first=first->next;
        }
    }
    while(first){
        temp->next=first;
        temp=temp->next;
        first=first->next;
    }
    while(second){
        temp->next=second;
        temp=temp->next;
        second=second->next;
    }
    return curr->next;
}

//kth from last
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    if(head==NULL || k==0){    
       return head;
   }
    LinkedListNode<int>*temp=new LinkedListNode<int>(-1);
    temp->next=head;
    LinkedListNode<int>*slow=temp;
    LinkedListNode<int>*fast=temp;
    for(int i=1;i<=k;i++){
        fast=fast->next;
    }
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return temp->next;
}

//detect cycle
bool detectCycle(Node *head)
{
	Node*fast=head;
    Node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
         
        fast=fast->next->next;
        slow=slow->next;
         if(fast==slow){
              return true;
          }
     
    }
    return false;
}

//begining of cycle
Node *firstNode(Node *head)
{
	Node*slow=head,*fast=head;
    int loop=0;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            loop=1;
            break;
        }
    }
    if(loop){
        slow=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
    return NULL;
}

//rotate k times
Node *rotate(Node *head, int k) {
     if(head==NULL || head->next==NULL || k==0){
         return head;
     }
    int len=1;
    Node*curr=new Node(0);
    curr=head;
    while(curr->next){
        curr=curr->next;
        len++;
    }
    curr->next=head;
    k=k%len;
    k=len-k;
    while(k--){
        curr=curr->next;
    }
    head=curr->next;
    curr->next=NULL;
    return head;
}