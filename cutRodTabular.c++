#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int cutRod (vector<int>&length,vector<int>&price,int n,int total){
    int t[n+1][total+1];
    for(int i =0;i<n+1;i++){
        t[i][0] =0;
    }
    for(int i = 1;i<total+1;i++){
        t[0][i] =0;
    }
    for(int i =1;i<n+1;i++){
        for(int j =1;j<total+1;j++){
            if(length[i-1]<=j){
                t[i][j] = max(t[i][j-length[i-1]]+price[i-1],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][total];
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