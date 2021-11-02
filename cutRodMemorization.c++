#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int t[1000][1000];
int cutRod (vector<int>&length,vector<int>&price,int n,int total){
    if(total == 0) return 0;
    if(n == 0)return 0;
    if(t[n][total]!=-1)return t[n][total];
    else if(length[n-1]<=total){
        t[n][total] = max(cutRod(length,price,n,total-length[n-1])+price[n-1],cutRod(length,price,n-1,total));
        return t[n][total];
    }
    else{
        t[n][total] = cutRod(length,price,n-1,total);
        return t[n][total];
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&t[0][0],&t[0][0]+(1000*1000),-1);
    vector<int>length {1,2,3,4};
    vector<int>price{2,5,7,8};
    int total = 5;
    cout<<cutRod(length,price,price.size(),total)<<endl;
}