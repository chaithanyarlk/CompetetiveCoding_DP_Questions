#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
//0/1 knapsack bounded

int knapsack(vector<int>&value,vector<int>&weights,int n,int capacity){
     if(capacity == 0|| n ==0){
          return 0;
          // if nothing is given then knapsack profit is going to be anyways 0
     }
     else if(weights[n-1]<=capacity){
          return (max(value[n-1]+knapsack(value,weights,n-1,capacity-weights[n-1]),knapsack(value,weights,n-1,capacity)));
          // include and not include case
     }
     else{
          return(knapsack(value,weights,n-1,capacity));
     }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> value { 60, 100, 120 };
    vector<int> weights  { 10, 20, 30 };
    int capacity = 50;
    cout<<knapsack(value,weights,weights.size(),capacity)<<endl;
}