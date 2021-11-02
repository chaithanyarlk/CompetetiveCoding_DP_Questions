#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int subsetCount(vector<int>&arr,int n,int sum){
    if(sum == 0)return 1;
    if(n == 0)return 0;
    else if(arr[n-1]<=sum){
        return subsetCount(arr,n-1,sum-arr[n-1])+subsetCount(arr,n-1,sum);
    }
    else{
        return subsetCount(arr,n-1,sum);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr{1, 1, 1, 1};
    int sum = 4;
    cout<<subsetCount(arr,arr.size(),sum)<<endl;
    
}