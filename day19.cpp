//1.next lexiograhical
vector<int> nextPermutation(vector<int> &arr, int N)

{
   int cnt=0;
   for(int i=0;i<N-1;i++){
       if(arr[i]>arr[i+1]){
          cnt++;  
       }
   }
   if(cnt==N-1)
   {
       sort(arr.begin(),arr.end());
       return arr;
   }
      int i;
      for( i=N-1;i>0;i--){
          if(arr[i]>arr[i-1]){
              i--;
              break;
          }
      }
      int k=i+1;
      int j=N-1;
      for(j;j>0;j--)
      {
          if(arr[i]<arr[j])
          {
              break;
          }
      }
      swap(arr[i],arr[j]);
   vector<int>::iterator ip;
   ip=arr.begin();
   ip=ip+k;
   reverse(ip, arr.end());    
   //sort(ip,arr.end());
      return arr;
   }

   //merge interval
   vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
     vector<vector<int>> ans;
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    
    for(int i=0;i<n;i++){
        if(ans.empty()){
            ans.push_back(intervals[0]);
        }
        else{
            vector<int>&v=ans.back();
            int temp=v[1];
            if(intervals[i][0]<=temp){
                v[1]=max(temp,intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
    }
    return ans;
}
//3 missing and repeated
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int an[n+1]={0};
   for(auto a:arr){
       an[a]++;
   }
   pair<int,int> p;
   for(int i=1;i<n+1;i++){
       if(an[i]==0){
           p.first = i;
       }
       if(an[i]>1){
           p.second = i;
       }
   }
return p;
	
}

//mergek array
#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap; // (element, vector no, index of that vector)
    
    /* step 1: pushing all the first elements of each vector */
    for(int i=0; i<k; i++)
    {
        int first_elem = arr[i][0];
        min_heap.push(make_pair(first_elem, make_pair(i, 0)));
    }
    
    vector<int> res;
    while(!min_heap.empty())
    {
        int elem = min_heap.top().first;
        int vect_no = min_heap.top().second.first;
        int vect_index = min_heap.top().second.second;
        
        min_heap.pop();
        res.push_back(elem);
        
        /* we are supposed to push the next element from the same vector from which we have popped if it is in the index limit. the intuition is true bcoz every vector is sorted. otherwise leave it. */
        if(vect_index+1 < arr[vect_no].size())
        {
            min_heap.push(make_pair(arr[vect_no][vect_index+1], make_pair(vect_no, vect_index+1)));
        }
    }
    
    return res;
}


