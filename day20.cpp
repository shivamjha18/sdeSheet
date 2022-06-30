//kth largest
class Kthlargest {
public:
   priority_queue<int,vector<int>,greater<int>>pq;
    Kthlargest(int K, vector<int> &arr) {
       for (int i=0;i<arr.size();i++)
           pq.push(arr[i]);
      
    }

    void add(int num) {
         if (num <= pq.top())
            return;
        pq.push(num);
        pq.pop();
    }

    int getKthLargest() {
       
        return pq.top();
       // Write your code here.
    }

};

//2-kth largest
int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=0;i<K;i++){
        pq.push(arr[i]);
    }
    for(int i=K;i<size;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

//island
void count_islands(int i, int j, int n ,int m, int **arr)
{
    if(i>=0 && i<n && j>=0 && j<m && arr[i][j]==1)
    {
        arr[i][j]=0;
        
        count_islands(i,j+1,n,m,arr);
        count_islands(i+1,j,n,m,arr);
        count_islands(i,j-1,n,m,arr);
        count_islands(i-1,j,n,m,arr);
        count_islands(i-1,j+1,n,m,arr);
        count_islands(i+1,j+1,n,m,arr);
        count_islands(i-1,j-1,n,m,arr);
        count_islands(i+1,j-1,n,m,arr);
    }
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                count++;
                count_islands(i,j,n,m,arr);
            }
        }
    }
    return count;
}

//4- book allocate
bool isPossible(int n, int m, vector<int> time, long long int mid)
{
    int day = 1;
    long long int reqTime = 0;
    for(int i=0; i<m; i++)
    {
        if(reqTime + time[i] <= mid)
        {
            reqTime += time[i];
        }
        else
        {
            day++;
            if(day>n || time[i] > mid)
            {
                return false;
            }
            reqTime = time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long start = 0;
    long long totalTime = 0;
    for(int i=0; i<time.size(); i++)
    {
        totalTime+=time[i];
    }
    long long end = totalTime;
    long long ans = -1;
    while(start<=end)
    {
        long long mid = start + (end-start)/2;
        if(isPossible(n, m, time, mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return ans;
}