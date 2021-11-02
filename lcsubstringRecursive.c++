#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int length = -1;
int lcsubstring(string*a,string *b,int n,int m){
    if( n ==0 ||m ==0)return 0;
    if((*a)[n-1] == (*b)[m-1]){
        int val = (lcsubstring(a,b,n-1,m-1)+1);
        if(length < val){
            length = val;
        }
        return val;
    }
    else{
        int val = max(lcsubstring(a,b,n-1,m),lcsubstring(a,b,n,m-1));
        if(val>length)length = val;
        return 0;
    }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a = "GeeksforGeeks";
    string b = "GeeksQuiz";
    lcsubstring(&a,&b,a.size(),b.size());
    cout<<length<<endl;
}