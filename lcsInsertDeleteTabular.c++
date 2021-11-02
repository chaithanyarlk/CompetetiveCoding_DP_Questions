#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int lcsInsertDelete(string a,string b,int n,int m){
    int t[n+1][m+1];
    for(int i = 0;i<n+1;i++)t[i][0] = 0;
    for(int i = 1;i<m+1;i++)t[0][i] = 0;
    for(int i =1;i<n+1;i++){
        for(int j =1;j<m+1;j++){
            if(a[i-1]==b[j-1]){
                t[i][j] = t[i-1][j-1]+1;
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return n+m-2*t[n][m];
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a = "heap";
    string b = "pea";
    cout<<lcsInsertDelete(a,b,a.size(),b.size());
}