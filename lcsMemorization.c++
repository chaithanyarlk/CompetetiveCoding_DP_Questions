#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int t[1000][1000];
int lcs(string*a,string *b,int n,int m){
    if(n == 0 || m==0)return 0;
    if(t[n][m] !=-1)return t[n][m];
    else if((*a)[n-1] == (*b)[m-1])
    {
        t[n][m] =  lcs(a,b,n-1,m-1)+1;
        return t[n][m];
        
    }
    else{
        t[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
        return t[n][m];
    }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&t[0][0],&t[0][0]+(1000*1000),-1);
    string a = "GXTXAYB";
    string b = "AGGTAB";
    cout<<lcs(&a,&b,a.size(),b.size())<<endl;
}