#include<bits/stdc++.h>
using namespace std;

int t[1000];
int lIS(vector<int>&arr,int n,int M){
    int m1=0,m2=0;
    if(n == 0)return 0;
    if(t[n]!=-1)return t[n];
    if(arr[n-1]<M)
    m1 = lIS(arr,n-1,arr[n-1])+1;
    m2 = lIS(arr,n-1,M);
    t[n] = max(m1,m2);
    return t[n];
}
int main(){
    fill(&t[0],&t[0]+1000,-1);
    vector<int>arr { 3, 10, 2, 1, 20};
    int val = lIS(arr,arr.size(),100000);
    cout<<val+1<<endl;
}