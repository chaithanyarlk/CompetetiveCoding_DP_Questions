#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
ll mcm (vector<ll>&matrix,int n){
    int t[n+1][n+1];
    for(int i = 0;i<n+1;i++)t[i][i] = 0;
    for(int l = 1;l<n;l++){
        for(int i = 1;i<=(n-l);i++){
            int j = i + l;
            int M = INT_MAX;
            for(int k = i;k<j;k++){
                int temp = t[i][k]+t[k+1][j]+matrix[i-1]*matrix[k]*matrix[j];
                if(temp<M){
                    M = temp;
                }
            }
            t[i][j] = M;
        }
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 0;j<n+1;j++){
            if(i<=j){
                cout<<t[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return t[1][n];
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll>matrix = {10, 30, 5, 60};
    cout<<mcm(matrix,matrix.size()-1)<<endl;
}