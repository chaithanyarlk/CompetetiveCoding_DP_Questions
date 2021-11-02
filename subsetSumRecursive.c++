#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int subsetSum(vector<int>&arr,int n,int sum){
    if(sum == 0) return 1;// if sum is 0 no element need to be included so obviously true
    if(n == 0) return 0;// base case if no array possibly we can't have suset which meets requirement
    else if(arr[n-1]<=sum){
        // Include case
        // max() because if any case gave true or any subset gave true then true only
        return max(subsetSum(arr,n-1,sum-arr[n-1]),subsetSum(arr,n-1,sum));
    }
    else{
        // Element larger than sum discard and move to next
        return subsetSum(arr,n-1,sum);
    }
    
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr {3, 34, 4, 12, 5, 2};
    int sum = 30;
    cout<<subsetSum(arr,arr.size(),sum)<<endl;
}