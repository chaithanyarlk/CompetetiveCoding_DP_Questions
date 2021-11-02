#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int t[1000][1000];
int coinMinCount(vector<int>&coins,int n ,int amt){
    if(amt == 0)return 0;
    if(n == 0) return 1e5;
    if(t[n][amt]!= -1) return t[n][amt];
    else if(coins[n-1]<=amt){
        t[n][amt]= min(coinMinCount(coins,n,amt-coins[n-1])+1,coinMinCount(coins,n-1,amt));
        return t[n][amt];
    }
    else{
        t[n][amt]= coinMinCount(coins,n-1,amt);
        return t[n][amt];
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&t[0][0],&t[0][0]+(1000*1000),-1);
    vector<int>coins {1,2,3};
    int amt = 5;
    cout<<coinMinCount(coins,coins.size(),amt)<<endl;
}