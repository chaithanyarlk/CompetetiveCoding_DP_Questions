#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int subsetCount(vector<int>&arr,int n,int sum){
    int t[n+1][sum+1];
    for(int i = 0;i<n+1;i++){
        t[i][0] = 1;
    }
    for(int i = 1;i<sum+1;i++){
        t[0][i] = 0;
    }
    for(int i =1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=sum){
                t[i][j] = t[i-1][j-arr[i-1]]+t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr{1, 2, 3, 3};
    int sum = 6;
    cout<<subsetCount(arr,arr.size(),sum)<<endl;
    
}