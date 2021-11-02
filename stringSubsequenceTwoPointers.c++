#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

bool stringSubsequence(string a, string b,int n,int m){
    int i = 0,j=0,count = 0;
    while(i<n&&j<m){
        if(a[i] == b[j]){
            count++;
            i++;
        }
        j++;
    }
    if(n == count)return true;
    return false;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a = "abc";
    string b = "ahbgdc";
    cout<<stringSubsequence(a,b,a.size(),b.size())<<endl;
}