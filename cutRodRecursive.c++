#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int cutRod (vector<int>&length,vector<int>&price,int n,int total){
    if(total == 0) return 0;
    if(n == 0)return 0;
    else if(length[n-1]<=total){
        return max(cutRod(length,price,n,total-length[n-1])+price[n-1],cutRod(length,price,n-1,total));
    }
    else{
        return cutRod(length,price,n-1,total);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>length {1,2,3,4};
    vector<int>price{2,5,7,8};
    int total = 5;
    cout<<cutRod(length,price,price.size(),total)<<endl;
}