//bfs
#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    vector<int> ans;
    vector<int> vis(vertex,0);
    vector<int>adj[vertex];
    for(int i=0;i<edges.size();i++){
        adj[edges[i].second].push_back(edges[i].first);
        adj[edges[i].first].push_back(edges[i].second);
    }
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        sort(adj[i].begin(),adj[i].end());    
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        }
    }
    return ans;    
}

//min stack
#include<bits/stdc++.h>// Implement class for minStack.
class minStack
{
   int topp;
   int size;
   int *mini;
   int *arr;

public:
 
 // Constructor
 minStack() 
 { 
  size=10000001;
           topp=-1;
           arr=new int[size];
           mini=new int[size];
 }
 
 // Function to add another element equal to num at the top of stack.
 void push(int num)
 {topp=topp+1;
  arr[topp]=num;
          if(topp==0)
              mini[topp]=num;
        else
            mini[topp]=min(mini[topp-1],num);
 }
 
 // Function to remove the top element of the stack.
 int pop()
 {
  if(topp==-1)return -1;
           else
           {
               return arr[topp--];
           }
 }
 
 // Function to return the top element of stack if it is present. Otherwise return -1.
 int top()
 {
 if(topp==-1)return -1;
           else return arr[topp];
 }
 
 // Function to return minimum element of stack if it is present. Otherwise return -1.
 int getMin()
 {
  return (topp==-1)?-1:mini[topp];
 }
};

//stack implementation
// Stack class.
class Stack {
    int *arr;
    int size;
    int top1;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        size=capacity;
        top1=-1;
        arr=new int[size];
    }

    void push(int num) {
        // Write your code here.
        if(top1==-1){
            top1++;
            arr[top1]=num;
        }
        else if(top1==size){
            cout<<"array is full";
        }
        else{
            top1++;
            arr[top1]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(top1==-1){
            return -1;
        }else{
             return arr[top1--];
        }
       
    }
    
    int top() {
        // Write your code here.
        if(top1==-1){
            return -1;
        }
        else{
            return arr[top1];
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(top1==-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    int isFull() {
        // Write your code here.
        if(top1==size){
            return true;
        }else{
            return false;
        }
    }
    
};

//atoi
int atoi(string str) {
    int sign=1;
	int i=0;
	int ans=0;
	if(str[i]=='-'){
		sign=-1;
		i++;
	}
	for(;i<str.length();i++){
		if(str[i]-'0'>=0 && str[i]-'0'<=9){
			ans=ans*10+str[i]-'0';
		}
	}
	return ans*sign;
}
//clone
LinkedListNode<int> *itr=head;

 

       while(itr!=NULL)

       {  

           LinkedListNode<int> *front=itr->next;

           LinkedListNode<int> *dumy=new LinkedListNode<int> (itr->data);

       dumy->next=itr->next;

        itr->next=dumy;

        itr=front;

       }

   itr=head;

   while(itr!=NULL)

   {

       itr->next->random=itr->random;

       itr=itr->next->next;

   }

   itr=head;

   LinkedListNode<int>* copy=new LinkedListNode<int> (0);

   LinkedListNode<int> *newnode=copy;

   while(itr!=NULL)

   {

      LinkedListNode<int> *front=itr->next->next;

   copy->next=itr->next;

       itr->next=front;

       itr=front;

       copy=copy->next;

   }

 return newnode->next  ;

}

//count and say
string res = "1";
    for (int i=1;i<n;i++)
    {
        string temp = "";
        int ct = 1;
        for (int j=0; j<res.length()-1;j++)
        {
            if (res[j] == res[j+1])
                ct++;
            else
            {
                temp += (to_string(ct) + res[j]);
                ct = 1;
            }
        }
       temp += to_string(ct) + res[res.length()-1];
       res = temp;
    }
    return res;