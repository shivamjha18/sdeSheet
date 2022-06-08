//1 k max sum combination
#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int>pq;
    vector<int>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(a[i]+b[j]);
        }
    }
    for(int i=0;i<k;i++){
        int a=pq.top();
        pq.pop();
        v.push_back(a);
    }
    return v;
}

//2-powerset
void solve(vector<vector<int>>&ans,vector<int>&res,int index,vector<int>v){
    if(index==v.size()){
        ans.push_back(res);
        return;
    }
    solve(ans,res,index+1,v);
    res.push_back(v[index]);
    solve(ans,res,index+1,v);
    res.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>>ans;
    vector<int>res;
    solve(ans,res,0,v);
    return ans;
}
//3- reverse word in a string
#include<bits/stdc++.h>
string reverseString(string str)
{
  int n=str.size();
   string s="";
    vector<string>v;
    for(int i=0;i<n;i++){
        if(str[i]!=' '){
            s+=str[i];
            if(str[i+1]==' ' || i==n-1){
                v.push_back(s);
                s="";
            }
        }
    }
    string ans="";
    for(int i=v.size()-1;i>0;i--){
        ans.append(v[i]);
        ans+=' ';
    }
    ans.append(v[0]);
    return ans;
                               
}

//4-palindromic substring
#include<bits/stdc++.h>
void solve(string str,int start,int end,int& mx,string& ans){
  int flag=1,st=start,en=end;
    while(start<=end){
        if(str[start++]!=str[end--])
            flag=0;
        
    }
    if(flag==1){
        string res=str.substr(st,en-st+1);
        if(mx<res.size()){
            ans=res;
            mx=res.size();
        }
    }
}
string longestPalinSubstring(string str)
{
  unordered_map<char,int>mp;
    int mx=0;
    string ans="";
    for(int i=0;i<str.size();i++){
        mp[str[i]]=i;
    }
    for(int i=0;i<str.size();i++){
        solve(str,i,mp[str[i]],mx,ans);
    }
    return ans;
}
//5-ROMAN TO INT 
#include<bits/stdc++.h>
int romanToInt(string s) {
    vector<int>v;
    v.push_back(0);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='I')
            v.push_back(1);
        else if(s[i]=='V')
            v.push_back(5);
        else if(s[i]=='X')
            v.push_back(10);
        else if(s[i]=='L')
            v.push_back(50);
        else if(s[i]=='C')
            v.push_back(100);
        else if(s[i]=='D')
            v.push_back(500);
        else if(s[i]=='M')
            v.push_back(1000);
    }
    int ans=0;
    for(int i=v.size()-1;i>0;i--)
    {
        if(v[i]>v[i-1])
        {
            ans += v[i]-v[i-1];
            --i;
        }
            
        else
            ans += v[i];
    }
    return abs(ans);
}