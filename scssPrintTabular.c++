// LCS print only but while traversing max direction print the value of those also
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
string scssPrint(string a,string b,int n,int m){
    int t[n+1][m+1] ;
    for(int i = 0;i<n+1;i++)t[i][0]=0;
    for(int i = 1;i<m+11;i++)t[0][i] = 0;
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = t[i-1][j-1] +1;
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    string result = "";
    int i =n,j=m;
    while(i!=0 || j!=0){
        if(a[i-1] == b[j-1]){
            result += a[i-1];
            i--;j--;
        }
        else if(t[i-1][j]>=t[i][j-1]){
            result += a[i-1];
            i--;
        }
        else{
            result += b[j-1];
            j--;
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a = "AGGTAB";
    string b = "GXTXAYB";
    cout<<scssPrint(a,b,a.size(),b.size())<<endl;
}