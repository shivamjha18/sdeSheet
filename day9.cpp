// //1- count distinct element

// vector<int> countDistinctElements(vector<int> &arr, int k) 
// {
    
//     int n=arr.size();
//     if(n==0){
//         return {};
//     }
//     vector<int>v;
//     vector<int>ans;
//     for(int i=0;i<k;i++){
//         v.push_back(arr[i]);
//     }
//     set<int>s;
// 	for(int i=k;i<=n;i++){
//         s.insert(v.begin(),v.end());
//         ans.push_back(s.size());
//         v.erase(v.begin());
//         v.push_back(arr[i]);
//         s.clear();
        
//     }
//     return ans;
// }

