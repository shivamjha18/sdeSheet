//1-version count
#include<bits/stdc++.h>
int compareVersions(string a, string b) 
{
    // Write your code here
    int asize=a.length();
    int bsize=b.length();

    vector<string> anum;
    vector<string> bnum;
    string temp="";
    for(int i=0;i<asize;i++){


        if(a[i]=='.'){
            anum.push_back(temp);
            temp="";
        }else{
            temp+=a[i];
        }
    }
    anum.push_back(temp);
    temp="";
    
    for(int i=0;i<bsize;i++){
        
        if(b[i]=='.'){
            bnum.push_back(temp);
            temp="";
        }else{
            temp+=b[i];
        }
    }
    bnum.push_back(temp);
    temp="";
    
    int n=anum.size();
    int m=bnum.size();
    

    
    int maxl=max(n,m);
    
    for(int i=0;i<maxl;i++){
        string v1=i<n?anum[i]:"0";
        string v2=i<m?bnum[i]:"0";
        if(v1 > v2){
            if(v2.size()>v1.size()){
                return -1;
            }else{
                return 1;
            }
         
        }else if(v2 > v1){ // 3 > 03
            if(v1.size()>v2.size()){ // but 03 size is 2 and 3 size is 1. so 03 
                return 1;
            }else{
                return -1;
            }

        }
    }
    return 0;
}
//2- maximum meeting
#include<algorithm>
int maximumActivities(vector<int> &start, vector<int> &end) {
    int n=start.size();
    int c=1;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({end[i],start[i]});
    }
    sort(v.begin(),v.end());
    int j=0;
    for(int i=1;i<v.size();i++){
        if(v[i].second>=v[j].first){
            c++;
            j=i;
        }
    }
    return c;
}

//3-knapsack
#include<bits/stdc++.h>

bool static cmp(pair<int,int>a,pair<int,int>b )

{

  double r1 = (double)a.second/(double)a.first;

  double r2 = (double)b.second/(double)b.first;

  return r1>r2;

}

double maximumValue (vector<pair<int, int>>& items, int n, int w)

{

   sort(items.begin(),items.end(),cmp);

   double profit = 0;

   for(int i=0;i<n;i++)

   {

       if(w>0)

       {

           if(w>=items[i].first)

           {

               w = w-items[i].first;

               profit = profit + (double)items[i].second;

           }

           else

           {

               profit = profit + (double)items[i].second*((double)w/(double)items[i].first);

               w=0;

           }

       }

       else break;

   }

   return profit;

}