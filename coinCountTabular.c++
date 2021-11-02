#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int coinCount(vector<int>&coins,int amt,int n){
    int t[n+1][amt+1];
    for(int i = 0;i<n+1;i++){
        t[i][0] = 1;
    }
    for(int i = 1;i<amt+1;i++) t[0][i] = 0;
    for(int i =1;i<n+1;i++){
        for(int j =1;j<amt+1;j++){
            if(coins[i-1]<=j){
                t[i][j] = t[i][j-coins[i-1]]+t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][amt];
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>coins {2, 5, 3, 6};
    int amount = 10;
    cout<<coinCount(coins,amount,coins.size())<<endl;
}