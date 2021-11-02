#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int subsetSum(vector<int>&arr,int n,int sum){
    int t[n+1][sum+1];
    for(int i = 0;i<n+1;i++){
        t[i][0] = 1;
    }
    for(int i = 1;i<sum+1;i++){
        t[0][i] = 0;
    }
    for(int i = 1;i<n+1;i++){
        for(int j =1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j] = max(t[i-1][j-arr[i-1]],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    // for(int i =0;i<n+1;i++){
    //     for(int j =0;j<sum+1;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return t[n][sum];
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr {3, 34, 4, 12, 5, 2};
    int sum = 30;
    cout<<subsetSum(arr,arr.size(),sum)<<endl;
}