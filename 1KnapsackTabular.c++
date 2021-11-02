#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
//0/1 knapsack bounded

int knapsack(vector<int>&val,vector<int>&wt,int n,int W){
     int arr[n+1][W+1];
       for(int i =0;i<W+1;i++){
           arr[0][i] = 0;
       }
       for(int i =0;i<n+1;i++){
           arr[i][0] = 0;
       }
       for(int i = 1;i<n+1;i++){
           for(int j =1;j<W+1;j++){
               if(wt[i-1]<=j){
                   arr[i][j] = max(val[i-1]+arr[i-1][j-wt[i-1]],arr[i-1][j]);
               }
               else{
                   arr[i][j] = arr[i-1][j];
               }
           }
       }
       
       return arr[n][W];
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> value {1,2,3};
    vector<int> weights  { 4,5,1 };
    int capacity = 4;
    cout<<knapsack(value,weights,weights.size(),capacity)<<endl;
}