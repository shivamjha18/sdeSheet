//1
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	vector<pair<int,int>>v;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                v.push_back({i,j});
            }
        }
    }
    for(int i=0;i<v.size();i++){
        int row=v[i].first,col=v[i].second;
        int j=0;
        while(j<n){
            matrix[j][col]=0;
            j++;
        }
        j=0;
        while(j<m){
            matrix[row][j]=0;
            j++;
        }
    }
}

//2
#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==target){
                return true;
            }
        }
        
    }
    return false;
}

//3
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	map<int,int>mp;
    int x=n/2;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if(it.second>x){
            return it.first;
        }
    }
    return -1;
}

//4
#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int>v;
    int n=arr.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int x=n/3;
    for(auto it:mp){
        if(it.second>x){
            v.push_back(it.first);
        }
    }
    return v;

}


//5

#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  int sum = 0;

 int maxi = 0;

 int n = arr.size();

 unordered_map<int ,int> mp;

 

 for(int i = 0 ;i<n ; i++){

     sum+= arr[i];

     if(sum == 0){

         maxi = i + 1;

     }else{

         if(mp.find(sum) != mp.end()){

             maxi = max(maxi , i-mp[sum]);

         }

         else{

             mp[sum] = i;

         }

     }

 }

 return maxi;

}

//6
ode *findMiddle(Node *head) {
   Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}