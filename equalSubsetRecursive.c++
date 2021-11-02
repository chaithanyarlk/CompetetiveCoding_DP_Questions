#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int subSetEqual(vector<int>&arr,int n,int sum){
    if(sum == 0)return 1;
    if(n == 0) return 0;
    else if(arr[n-1]<=sum){
        return max(subSetEqual(arr,n-1,sum-arr[n-1]),subSetEqual(arr,n-1,sum));
    }
    else{
        return subSetEqual(arr,n-1,sum);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr {1, 5, 11, 5};
    int sum = accumulate(arr.begin(),arr.end(),0);
    if(sum%2 != 0)
    cout<<0<<endl;
    else
    cout<<subSetEqual(arr,arr.size(),sum/2)<<endl;
}