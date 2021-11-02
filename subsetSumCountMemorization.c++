#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int t[1000][1000];
int subsetCount(vector<int>&arr,int n,int sum){
    if(sum == 0)return 1;
    if(n == 0)return 0;
    if(t[n][sum] !=-1)return t[n][sum];
    else if(arr[n-1]<=sum){
        t[n][sum] = subsetCount(arr,n-1,sum-arr[n-1])+subsetCount(arr,n-1,sum);
        return t[n][sum];
    }
    else{
        t[n][sum] = subsetCount(arr,n-1,sum);
        return t[n][sum];
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&t[0][0],&t[0][0]+(1000*1000),-1);
    vector<int>arr{1, 2, 3, 3};
    int sum = 6;
    cout<<subsetCount(arr,arr.size(),sum)<<endl;
    
}