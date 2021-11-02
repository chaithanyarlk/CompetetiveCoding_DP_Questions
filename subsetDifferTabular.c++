#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int subsetDiffer(vector<int>&arr,int n,int sum){
    int t[n+1][sum+1];
    for(int i = 0;i<n+1;i++){
        t[i][0] = 1;
    }
    for(int i = 1;i<sum+1;i++){
        t[0][i] =0;
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            if(arr[i-1]<=j){
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
    vector<int>arr{1,2,1,3};
    int sum = accumulate(arr.begin(),arr.end(),0);
    for(int i = 0;i<arr.size();i++)arr[i] = 2*arr[i];
    int diff  = 1;
    cout<<subsetDiffer(arr,arr.size(),sum+diff)<<endl;
}