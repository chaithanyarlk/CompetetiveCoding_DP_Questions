#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int rem[1000][1000];

int subsetSum(vector<int>&arr,int n,int sum){
    if(sum == 0) return 1;// if sum is 0 no element need to be included so obviously true
    if(n == 0) return 0;
    // base case if no array possibly we can't have suset which meets requirement
    if(rem[n][sum]!=-1)return rem[n][sum];
    else if(arr[n-1]<=sum){
        // Include case
        // max() because if any case gave true or any subset gave true then true only
        rem[n][sum] = max(subsetSum(arr,n-1,sum-arr[n-1]),subsetSum(arr,n-1,sum));
        return rem[n][sum];
    }
    else{
        // Element larger than sum discard and move to next
        rem[n][sum] = subsetSum(arr,n-1,sum);
        return rem[n][sum];
    }
    
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&rem[0][0],&rem[0][0]+(1000*1000),-1);
    vector<int>arr {3, 34, 4, 12, 5, 2};
    int sum = 6;
    cout<<subsetSum(arr,arr.size(),sum)<<endl;
}