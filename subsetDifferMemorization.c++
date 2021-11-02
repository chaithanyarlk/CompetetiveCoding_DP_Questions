#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int t[1000][1000];
int subsetDiffer(vector<int>&arr,int n,int sum){
    if(sum == 0) return 1;
    if(n == 0) return 0;
    if(t[n][sum]!=-1)return t[n][sum];
    else if(arr[n-1]<=sum){
        t[n][sum] = subsetDiffer(arr,n-1,sum-arr[n-1])+subsetDiffer(arr,n-1,sum);
        return t[n][sum];
    }
    else{
        t[n][sum] = subsetDiffer(arr,n-1,sum);
        return t[n][sum];
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr{1,2,1,3};
    fill(&t[0][0],&t[0][0]+(1000*1000),-1);
    int sum = accumulate(arr.begin(),arr.end(),0);
    for(int i = 0;i<arr.size();i++)arr[i] = 2*arr[i];
    int diff  = 1;
    cout<<subsetDiffer(arr,arr.size(),sum+diff)<<endl;
}