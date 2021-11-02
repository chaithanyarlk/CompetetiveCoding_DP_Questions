#include<bits/stdc++.h>
using namespace std;
#define ll  int
#define PB push_back
ll t[1000][1000];
ll minFountain(vector<ll>&arr,ll sum,ll N,ll n){
    if(sum == 0)return 0;
    if(n == 0)return 10000;
    if(t[n][sum] != -1)return t[n][sum];
    ll M = min(N,n+arr[n]);
    ll m = max(1,n-arr[n]);
    int p;
    if(sum - (M-m+1)<=0)p=0;
    else p = sum- (M-m+1);
    ll m1 = 1+minFountain(arr,p,N,m-1);
    ll m2 = minFountain(arr,sum,n,n-1);
    t[n][sum] = min(m1,m2);
    return t[n][sum];
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&t[0][0],&t[0][0]+1000*1000,-1);
    vector<ll>arr {0,2, 1, 1, 2, 1}  ;
    cout<<minFountain(arr,arr.size()-1,arr.size()-1,arr.size()-1)<<endl;
}