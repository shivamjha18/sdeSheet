//1.inversion
#include <bits/stdc++.h> 

void merge(long long *arr,long long *temp,int s,int mid,int e,long long int& x) {
	int i=s;
	int j=mid+1;
	int k=s;
	while(i<=mid && j<=e){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			x += (mid-i+1);
		}
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}
	//copying temp elements  back to the array
	for(int i=s;i<=e;i++)
		arr[i]=temp[i];
}
void mergesort(long long *arr,long long *temp,int s,int e,long long int& x) {
	if(s>=e)
		return;
	int mid = s+(e-s)/2;
	mergesort(arr,temp,s,mid,x);
	mergesort(arr,temp,mid+1,e,x);
	merge(arr,temp,s,mid,e,x);
}


long long getInversions(long long *arr, int n){
    // Write your code here.
	long long int count=0;
	long long temp[n];
	mergesort(arr,temp,0,n-1,count);
	return count;
}
//2-longest increasing
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i]-1)!=s.end()){
            continue;
        }
        else{
            int count=0;
            int current=arr[i];
            while(s.find(current)!=s.end()){
                count++;
                current++;
            }
            ans=max(ans,count);
        }
    }
    return ans;
}

//3-subarray xor
map<int,int> mp;

    int xr =0 , count = 0;

    for(int i=0;i<arr.size();i++){

        xr ^=arr[i];

        if(xr == x) count++;

        if(mp.find(xr ^ x) != mp.end()) count += mp[xr ^ x];

        mp[xr]++;

    }

    return count;