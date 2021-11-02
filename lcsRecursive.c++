#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int lcs(string*a,string *b,int n,int m){
    if(n == 0 || m==0)return 0;
    else if((*a)[n-1] == (*b)[m-1])
    return lcs(a,b,n-1,m-1)+1;
    else{
        return max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
    }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a = "AEDFHR";
    string b = "ABCDGH";
    cout<<lcs(&a,&b,a.size(),b.size())<<endl;
}