#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int coinMinCount(vector<int>&coins,int n ,int amt){
    if(amt == 0)return 0;
    if(n == 0) return 1e5;
    else if(coins[n-1]<=amt){
        return min(coinMinCount(coins,n,amt-coins[n-1])+1,coinMinCount(coins,n-1,amt));
    }
    else{
        return coinMinCount(coins,n-1,amt);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>coins {1,2,3};
    int amt = 5;
    cout<<coinMinCount(coins,coins.size(),amt)<<endl;
}