#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int coinCount(vector<int>&coins,int amt,int n){
    if(amt == 0) return 1;
    if(n == 0) return 0;
    else if(coins[n-1]<=amt){
        return coinCount(coins,amt-coins[n-1],n)+coinCount(coins,amt,n-1);
    }
    else{
        return coinCount(coins,amt,n-1);
    }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>coins {2, 5, 3, 6};
    int amount = 10;
    cout<<coinCount(coins,amount,coins.size())<<endl;
}