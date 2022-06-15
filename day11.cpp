//1-pascal traingle
#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>>v;
    v.push_back({1});
    if(n==1) return v;
    v.push_back({1,1});
    if(n==2) return v;
    for(int i=2;i<n;i++){
        int k=v[i-1].size();
        vector<long long int>s(k+1,1);
        for(int j=1;j<k;j++){
            s[j]=v[i-1][j]+v[i-1][j-1];
        }
        v.push_back(s);
    }
    return v;
}

//2-modular
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	 long ans = 1;

       long xx =x;      
       while(n>0){
           if(n%2==0){
               xx=(xx%m*xx%m)%m;
               n=n>>1;
           } else{
               ans=(ans*xx%m)%m;
               n=n-1;
           }
       }

       return (int)(ans%m);
}

//3-chesstournament------

bool canPlace(int dist,int c,vector<int> positions,int n){
    int ninjasplaced=1;
    int recentplacedat=0;
    for(int i=1;i<n;i++){
        if(positions[i]-positions[recentplacedat] >= dist){ // if the room posion and prevly placed room pos mein distance agar >= dist hai then can be placed, 
            ninjasplaced++; // placed increment
            recentplacedat=i; // recen kaha pe daala woh index store.
        }
    }
    if(ninjasplaced>=c){ // agar placed >= c hai matlab saare place hogaye so return possible
        return true;
    }else{
        return false; //else cannot be placed.
    }
}


int chessTournament(vector<int> positions , int n ,  int c){
	
    sort(positions.begin(),positions.end()); // sort to find high and low easily.
    int l=0;
    int h=positions[n-1]-positions[0];
    int ans=0;
    // monotonous space for dist between rooms,
    /*
    if the array is 1 2 4 5, the min dist is 1(2,1) and max dist betweeb rooms is 4 (5-1);
    1 2 3 4 --> l at 1 and h at 4.
    */
    while(l<=h){
        int mid=(l+h)/2;
        if(canPlace(mid,c,positions,n)){ // with mid as a distance between rooms can be placed? yes then low=mid+1 cuz we want max dist possible
            ans=mid;
            l=mid+1;
        }else{ // else h=mid-1 cant be placed with mid as a distance between them.
            h=mid-1;
        }
    }
    
    return ans; // store and return the answer.
    
}