#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int maxKSubarray(vector<int>&arr,int n,int k){
    int sum = 0;
    for(int i =0;i<k;i++)sum+=arr[i];
    int M = sum;
    int j = k;
    int i = 0;
    while(j<n){
        sum = sum - arr[i];
        sum += arr[j];
        if(M < sum)M =sum;
        i++;
        j++;
    }
    return M;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr {100, 200, 300, 400};
    int k = 2;
    cout<<maxKSubarray(arr,arr.size(),k)<<endl;
}