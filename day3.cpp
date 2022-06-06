//1palindrom linked list
LinkedListNode<int>*reverse(LinkedListNode<int>*head){
   LinkedListNode<int>*curr=head;
   LinkedListNode<int>*prev=NULL;
    LinkedListNode<int>*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL) return true;
   LinkedListNode<int>*slow=head;
   LinkedListNode<int>*fast=head->next;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    LinkedListNode<int>*newh=slow->next;
    slow->next=NULL;
    newh=reverse(newh);
    LinkedListNode<int>*temp=head;
    while(temp!=NULL && newh!=NULL){
        if(temp->data!=newh->data){
            return false;
        }
        temp=temp->next;
        newh=newh->next;
    }
    return true;

}

//2 flattening linked list
Node*merge(Node*a,Node*b){
    Node*temp=new Node(0);
    Node*res=temp;
    while(a!=NULL && b!=NULL){
        if(a->data <b->data){
            temp->child=a;
            temp=temp->child;
            a=a->child;
        }
        else{
            temp->child=b;
            temp=temp->child;
            b=b->child;
        }
    }
    if(a){
        temp->child=a;
    }
    else{
        temp->child=b;
    }
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL){
        return head;
    }
    head->next=flattenLinkedList(head->next);
    head= merge(head,head->next);
    return head;
}

//3-remove duplicate from sorted array
#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) {
// 	map<int,int>mp;
//     for(int i=0;i<n;i++){
//         mp[arr[i]]++;
//     }
//     int count=0;
//     for(auto it:mp){
//         if(it.second){
//             count++;
//         }
//     }
//     return count;
    int c=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            c++;
        }
    }
    return c+1;
}

//4 minimun coin
int findMinimumCoins(int amount) 
{
        int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
       int count = 0;
       int i = 8;
   
   while(amount!=0){
       if(arr[i]>amount){
           i--;
       }
       else{
           amount -= arr[i];
           count++;
       }
   }
   return count;
}

//5
void helper(vector<int>&num,vector<int>&arr,int sum,int index){
    if(index<0){
        arr.push_back(sum);
        return;
    }
    helper(num,arr,sum,index-1);
    helper(num,arr,sum+num[index],index-1);
}
vector<int> subsetSum(vector<int> &num)
{
   vector<int>arr;
    helper(num,arr,0,num.size()-1);
    sort(arr.begin(),arr.end());
    return arr;
}