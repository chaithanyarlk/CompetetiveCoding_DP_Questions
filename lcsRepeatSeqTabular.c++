#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int lcsRepeatSeq(string a, string b, int n){
    int t[n+1][n+1];
    for(int i = 0;i<n+1;i++)t[i][0]= 0;
    for(int i = 1;i<n+1;i++)t[0][i] = 0;
    for(int i = 1;i<n+1;i++){
        for(int j =1;j<n+1;j++){
            if(a[i-1]==b[j-1] && i!=j){
                t[i][j] = t[i-1][j-1] +1;
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][n];
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a = "aab";
    cout<<lcsRepeatSeq(a,a,a.size())<<endl;
}