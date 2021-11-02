#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int t[1000][1000];
int knapsackUnbound(vector<int>&weights,vector<int>&values,int n,int capacity){
    if(capacity == 0 || n == 0)return 0;
    if(t[n][capacity]!=-1)return t[n][capacity];
    else if(weights[n-1]<=capacity){
        t[n][capacity] = max(values[n-1]+knapsackUnbound(weights,values,n,capacity-weights[n-1]),knapsackUnbound(weights,values,n-1,capacity));
        return t[n][capacity] ;
    }
    else{
        t[n][capacity] = knapsackUnbound(weights,values,n-1,capacity);
        return t[n][capacity] ;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&t[0][0],&t[0][0]+(1000*1000),-1);
    vector<int>val{10, 30, 20};
    vector<int>weights{5,10,15};
    int capacity = 100;
    cout<<knapsackUnbound(weights,val,val.size(),capacity)<<endl;
    
}