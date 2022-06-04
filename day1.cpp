//1
#include<bits/stdc++.h>
void sort012(int *arr, int n)
{
//    sort(arr,arr+n);
    int i=0,j=0,k=n-1;
    while(j<=k){
        switch(arr[j]){
            case 0:
                swap(arr[i],arr[j]);
                i++;
                j++;
                break;
            case 1:
                j++;
                break;
            case 2:
                swap(arr[j],arr[k]);
                k--;
        }
    }
 
}

//2
#include<bits/stdc++.h>
int findDuplicate(vector<int> &arr, int n){
	map<int,int>mp;
    for(auto it:arr){
        mp[it]++;
    }
    auto it=mp.begin();
    for(;it!=mp.end();it++){
        if(it->second>=2){
            return it->first;
        }
    }
    return -1;
}

//3
#include<bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   	vector<vector<int>> result;
    vector<int> v;
    int n=arr.size();
    
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == s) {
				if(arr[i] > arr[j]) 
                {
                    v.push_back(arr[j]);
                	v.push_back(arr[i]);
                }
                else 
                {
                    v.push_back(arr[i]); 
                	v.push_back(arr[j]);
                }
                result.push_back(v);
            }
            v.clear();
        }
    }
    sort(result.begin(), result.end());
    return result;
}

//4
#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int>st;
    vector<int>v(n);
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        int a=arr[i];
        while(!st.empty() && a>=st.top()){
            st.pop();
        }
        if(!st.empty()){
            v[i]=st.top();
            st.push(a);
        }
        else{
            v[i]=-1;
            st.push(a);
        }
    }
    return v;

}

//5
void sort1(stack<int>&st,int x){
    if(st.empty() || st.top()<x){
        st.push(x);
        return;
    }
    int val=st.top();
    st.pop();
    sort1(st,x);
    st.push(val);
}

void sortStack(stack<int> &st)
{
	if(st.empty()){
        return;
    }
    int x=st.top();
    st.pop();
    sortStack(st);
    sort1(st,x);
}

//6
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>v(n);
    for(int i=n-1;i>=0;i--){
        int a=arr[i];
        while(a<=st.top()){
            st.pop();
        }
        
            v[i]=st.top();
            st.push(a);
        
    }
    return v;
}

//7
bool f(int n, int k, vector<int> &arr,vector<vector<int>>&dp){
    if(k==0){
        return true;
    }
    if(n==0){
        return (arr[0]==k);
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    bool non=f(n-1,k,arr,dp);
    bool take=false;
    if(k>=arr[n]){
        take=f(n-1,k-arr[n],arr,dp);
    }
    
    return dp[n][k]=take or non;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return(f(n-1,k,arr,dp));
}