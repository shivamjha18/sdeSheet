//1-4 element sumto given value
#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            int p=target-arr[i]-arr[j];
            int left=i+1;
            int right=j-1;
            while(left<right){
                if(p==arr[left]+arr[right]){
                    return "Yes";
                }
                else if(arr[left]+arr[right]>p){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
       
    }
     return "No";
}

vector<vector<int>> ans;
    
    //sort first so it becomes easy
    sort(arr.begin(), arr.end());
    int left,right;	//2ptr approach
    for(int i=0; i<n; i++){
        left = i+1;
        right = n-1;
        //terminary condn
        while(left<right){
            //check for sum, here we fix arr[i], and then form 2 pair sum over remaining elements of array
            if(arr[i] + arr[left] + arr[right] == K){
                //we got it, push it back
                ans.push_back({arr[i], arr[left], arr[right]});
                int x = arr[left];
                int y = arr[right];
                //skipping the same returned elements of left and right if they are present in duplicate form
                while(left<right && arr[left] == x){
                    left++;
                }
                while(left<right && arr[right] ==y){
                    right--;
                }
            } //if end
            //if not match then in else cases move left/right pointer as per condition
            else if(arr[i] + arr[left] + arr[right] < K){
                left++;
            }
            else{
                //arr[i] + arr[left] + arr[right] > K
                right--;
            }
        }//while end
        //we need to skip duplicates of arr[i], ith element if present
        while(i+1<n && arr[i]==arr[i+1]){
            i++;
        }
    }//for end
    return ans;