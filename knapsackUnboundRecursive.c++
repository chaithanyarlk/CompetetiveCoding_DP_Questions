#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int knapsackUnbound(vector<int>&weights,vector<int>&values,int n,int capacity){
    if(capacity == 0 || n == 0)return 0;
    else if(weights[n-1]<=capacity){
        return max(values[n-1]+knapsackUnbound(weights,values,n,capacity-weights[n-1]),knapsackUnbound(weights,values,n-1,capacity));
    }
    else{
        return knapsackUnbound(weights,values,n-1,capacity);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>val{10, 30, 20};
    vector<int>weights{5, 10, 15};
    int capacity = 100;
    cout<<knapsackUnbound(weights,val,val.size(),capacity)<<endl;
    
}